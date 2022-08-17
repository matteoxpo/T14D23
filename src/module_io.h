#ifndef SRC_MODULE_IO_H_
#define SRC_MODULE_IO_H_

#include <stdio.h>

int saveScan(int *input);
char *charInput(int flag);
char *charInputFromFile(FILE *f);
int charInputInFile(FILE *f, char *write);
void str_output(char *str);
char *s21_strcat(char *str1, char *str2);

#endif  // SRC_MODULE_IO_H_
