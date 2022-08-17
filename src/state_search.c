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
    int d, m, y;
    char c;
    if (scanf("%d.%d.%d%c", &d, &m, &y, &c) == 4 &&
        (c == '\n' || c == '\0' || c == EOF)) {
      struct date_struct dat;
      int flag = 0;
      for (int i = 0; i < get_records_count_in_file(f); i++) {
        dat = read_record_from_file(f, i);
        if (dat.day == d && dat.month == m && dat.year == y) {
          flag = 1;
          break;
        }
      }
      if (!flag)
        printf("n/a");
      else
        printf("%d\n", dat.code);

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
