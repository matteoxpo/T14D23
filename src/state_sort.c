#include <stdio.h>
#include <stdlib.h>

#include "date_struct.h"
#include "module_io.h"

void struct_output(struct date_struct buff) {
  int code;
  int status;
  printf("%d:%d:%d:%d:%d:%d\t%d\t%d\n", buff.year, buff.month, buff.day,
         buff.houre, buff.minute, buff.sec, buff.status, buff.code);
}

void sorting(FILE *f) {
  int size = get_records_count_in_file(f);
  struct date_struct d1;
  struct date_struct d2;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      d1 = read_record_from_file(f, j);
      d2 = read_record_from_file(f, j + 1);
      if (date_compare_more(d1, d2)) {
        swap_records_in_file(f, j, j + 1);
      }
    }
  }
}

int main() {
  char *input = charInput(0);
  FILE *f = fopen(input, "rb+");

  if (input != NULL) free(input);
  if (f != NULL) {
    int lines_count = get_records_count_in_file(f);
    // int *sorted = (int *)malloc(lines_count * sizeof(int));
    printf("%d", lines_count);

    sorting(f);
    for (int i = 0; i < lines_count; i++) {
      struct_output(read_record_from_file(f, i));
    }
    // swap_records_in_file(f, 1467, 1466);

    fclose(f);
  } else {
    printf("n/a");
    printf("\n%s", input);
  }
  return 0;
}
