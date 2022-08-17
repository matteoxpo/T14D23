#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_files_common_functions.h"
#include "date_struct.h"
#include "module_io.h"

int main() {
  char *path = charInput();
  FILE *f = fopen(path, "r");
  if (f != NULL) {
    int y1, m1, d1;
    int y2, m2, d2;
    if (scan_date(&d1, &m1, &y1) && scan_date(&d2, &m2, &y2)) {
      struct date_struct dat;
      FILE *buff = tmpfile();
      int size = get_records_count_in_file(f);
      for (int i = 0, k = 0; i < size; i++) {
        dat = read_record_from_file(f, i);
        if (date_compare_less(dat, y1, m1, d1, 1)) {
          write_record_in_file(buff, &dat, k);
          k++;
        }
        if (date_compare_less(dat, y2, m2, d2, 0)) {
          write_record_in_file(buff, &dat, k);
          k++;
        }
      }
      fclose(f);

      f = fopen(path, "ab+");
      size = get_records_count_in_file(buff);
      for (int i = 0; i < size; i++) {
        dat = read_record_from_file(buff, i);
        write_record_in_file(f, &dat, i);
      }
      file_output(f);
      printf("\n\n%d", size);
      fclose(f);

      fclose(buff);

    } else {
      printf("n/a");
    }
    fclose(f);
  } else {
    printf("n/a");
  }
  if (path) free(path);
  return 0;
}
