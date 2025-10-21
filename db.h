#ifndef DB_H
#define DB_H

#include <stdlib.h>

typedef enum {
  INT,
  STRING,
  CHAR,
  FLOAT
} type_t;

typedef union {
    char *string;
    char c;
    int i;
    float f;
} val_t;

typedef struct column {
    char *col_name;
    type_t type;
} col_t;

typedef struct row {
    val_t *val;
} row_t;

typedef struct table {
    char *table_name;
    col_t *cols;
    row_t *rows;
    size_t ncols;
    size_t nrows;
} table_t;

// Table management functions
table_t *create_table(const char* name);
void destroy_table(table_t *table);

// Column operations
void add_column(table_t *table, const char *name, type_t type);

// Row operations
void add_row(table_t *table, val_t *vals);

// Display functions
void print(table_t *table);

#endif // DB_H