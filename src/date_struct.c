
#include "date_struct.h"

struct date_struct read_record_from_file(FILE *pfile, int index) {
  int offset = index * sizeof(struct date_struct);
  fseek(pfile, offset, SEEK_SET);
  struct date_struct record;
  fread(&record, sizeof(struct date_struct), 1, pfile);
  rewind(pfile);
  return record;
}

int date_compare_more(struct date_struct d1, struct date_struct d2) {
  int res = 1;
  if (d1.year < d2.year) res = 0;
  if (d1.year > d2.year) res = 1;
  if (d1.year == d2.year) {
    if (d1.month < d2.month) res = 0;
    if (d1.month > d2.month) res = 1;
    if (d1.month == d2.month) {
      if (d1.day < d2.day) res = 0;
      if (d1.day > d2.day) res = 1;
      if (d1.day == d2.day) {
        if (d1.houre < d2.houre) res = 0;
        if (d1.houre > d2.houre) res = 1;
        if (d1.houre == d2.houre) {
          if (d1.sec < d2.sec) res = 0;
          if (d1.sec > d2.sec) res = 1;
          if (d1.sec == d2.sec) res = 0;
        }
      }
    }
  }
  return res;
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

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
  struct date_struct record1 = read_record_from_file(pfile, record_index1);
  struct date_struct record2 = read_record_from_file(pfile, record_index2);

  write_record_in_file(pfile, &record1, record_index2);
  write_record_in_file(pfile, &record2, record_index1);
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