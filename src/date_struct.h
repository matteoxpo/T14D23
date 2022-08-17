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

int date_struct_input(struct date_struct *d);
int date_compare_more(struct date_struct d1, struct date_struct d2);
int date_compare_less(struct date_struct d1, int y, int m, int d, int flag);
void struct_output(struct date_struct buff);
int get_ymd_sum(struct date_struct d);

#endif  // SRC_DATE_STRUCT_H_
