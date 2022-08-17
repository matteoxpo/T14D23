#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_files_common_functions.h"
#include "date_struct.h"
#include "module_io.h"

void menu();

int main() {
  menu();
  return 0;
}

void menu() {
  char *path = charInput();
  FILE *f = fopen(path, "rb+");

  int command;
  if (f != NULL && saveScan(&command)) {
    char *write = NULL;
    struct date_struct date;
    int lines;
    switch (command) {
      case 0:
        file_output(f);
        break;
      case 1:
        sorting(f);
        file_output(f);
        break;
      case 2:
        if (date_struct_input(&date)) {
          lines = get_records_count_in_file(f);
          write_record_in_file(f, &date, lines);
          sorting(f);
          file_output(f);
        } else {
          printf("n/a");
        }
        break;
      default:
        printf("n/a");
        break;
    }
    if (write) free(write);
  } else {
    printf("n/a");
  }
  if (path) free(path);
  if (f) fclose(f);
}
