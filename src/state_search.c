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
    if (scan_date(&d, &m, &y)) {
      int index = search(f, d, m, y);
      if (index == -1) {
        printf("n/a");
      } else {
        struct date_struct dat = read_record_from_file(f, index);
        printf("%d\n", dat.code);
      }
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
