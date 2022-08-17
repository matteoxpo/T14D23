
#include "date_struct.h"

#include <stdlib.h>

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

int date_struct_input(struct date_struct *date) {
  int res = 0;

  int y;
  int mo;
  int d;
  int h;
  int min;
  int se;
  int stat;
  int cod;
  char c;

  if (scanf("%d %d %d %d %d %d %d %d%c", &y, &mo, &d, &h, &min, &se, &stat,
            &cod, &c) == 9 &&
      (c == '\n' || c == '\0')) {
    date->year = y;
    date->month = mo;
    date->day = d;
    date->houre = h;
    date->minute = min;
    date->sec = se;
    date->status = stat;
    date->code = cod;
    res = 1;
  }

  return res;
}

void struct_output(struct date_struct buff) {
  printf("%d:%d:%d:%d:%d:%d\t%d\t%d\n", buff.year, buff.month, buff.day,
         buff.houre, buff.minute, buff.sec, buff.status, buff.code);
}
