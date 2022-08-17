#ifndef SRC_BINARY_FILES_COMMON_FUNCTIONS_H_
#define SRC_BINARY_FILES_COMMON_FUNCTIONS_H_
#include <stdlib.h>

#include "date_struct.h"

struct date_struct read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile,
                          const struct date_struct *record_to_write, int index);

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_records_count_in_file(FILE *pfile);
int get_file_size_in_bytes(FILE *pfile);
void sorting(FILE *f);
void file_output(FILE *f);
int search(FILE *f, int d, int m, int y);

#endif  // SRC_BINARY_FILES_COMMON_FUNCTIONS_H_
