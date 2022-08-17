#ifndef SRC_DATE_STRUCT_H_
#define SRC_DATE_STRUCT_H_

#include <stdio.h>

struct date_struct {
  int year;
  int month;
  int day;
  int houre;
  int minute;
  int sec;
  int status;
  int code;
};

struct date_struct read_record_from_file(FILE *pfile, int index);
int date_compare_more(struct date_struct d1, struct date_struct d2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
void write_record_in_file(FILE *pfile,
                          const struct date_struct *record_to_write, int index);
#endif  // SRC_DATE_STRUCT_H_
