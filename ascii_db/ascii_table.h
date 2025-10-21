#ifndef ASCII_TABLE_H
#define ASCII_TABLE_H

#define MAX_COLUMNS 10
#define MAX_COLUMNS_WIDTH 50

void print_table(const char** headers, int num_headers, char* data[][MAX_COLUMNS], int num_rows);

#endif
