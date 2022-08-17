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
void struct_output(struct date_struct buff);

#endif  // SRC_DATE_STRUCT_H_
