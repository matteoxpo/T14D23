#include "binary_files_common_functions.h"

#include <stdlib.h>

#include "date_struct.h"

struct date_struct read_record_from_file(FILE *pfile, int index) {
  int offset = index * sizeof(struct date_struct);

  fseek(pfile, offset, SEEK_SET);

  struct date_struct record;
  fread(&record, sizeof(struct date_struct), 1, pfile);

  rewind(pfile);

  return record;
}

void write_record_in_file(FILE *pfile,
                          const struct date_struct *record_to_write,
                          int index) {
  int offset = index * sizeof(struct date_struct);

  fseek(pfile, offset, SEEK_SET);

  fwrite(record_to_write, sizeof(struct date_struct), 1, pfile);

  fflush(pfile);

  rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
  struct date_struct record1 = read_record_from_file(pfile, record_index1);
  struct date_struct record2 = read_record_from_file(pfile, record_index2);

  write_record_in_file(pfile, &record1, record_index2);
  write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
  int size = 0;
  fseek(pfile, 0, SEEK_END);
  size = ftell(pfile);

  rewind(pfile);

  return size;
}

int get_records_count_in_file(FILE *pfile) {
  return get_file_size_in_bytes(pfile) / sizeof(struct date_struct);
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

void file_output(FILE *f) {
  for (int i = 0; i < get_records_count_in_file(f); i++) {
    struct_output(read_record_from_file(f, i));
    if (i != get_records_count_in_file(f) - 1) printf("\n");
  }
}

int search(FILE *f, int d, int m, int y) {
  struct date_struct dat;
  int i = -1;
  for (i = 0; i < get_records_count_in_file(f); i++) {
    dat = read_record_from_file(f, i);
    if (dat.day == d && dat.month == m && dat.year == y) {
      break;
    }
  }
  return i;
}
