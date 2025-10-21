#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ascii_db/ascii_table.h"
#include "db.h"

#define MAX_COLS 10
#define __offsetof(structure, member) ((size_t)&(((structure *)0)->member))
// typedef enum __type{
//   INT,
//   STRING,
//   CHAR,
//   FLOAT
// } type_t;

// typedef union{
// 	char *string;
// 	char c;
// 	int i;
// 	float f;
// } val_t;
// typedef struct column{
// 	char *col_name;
// 	type_t type;
// } col_t;

// typedef struct row{
// 	val_t *val;
// } row_t;

// typedef struct table{
// 	char *table_name;	// 0
// 	col_t *cols;		// 8
// 	row_t *rows;		// 16
// 	size_t ncols;		// 24
// 	size_t nrows;		// 32
// } table_t;				// size = 40 bytes

table_t *create_table(const char *name)
{
	table_t *tab = malloc(sizeof(table_t));
	if (tab == NULL)
		return NULL;
	tab->table_name = strdup(name);
	tab->ncols = 0;
	tab->nrows = 0;
	tab->cols = malloc(sizeof(col_t) * MAX_COLS);
	tab->rows = NULL;
	return tab;
}

void add_column(table_t *table, const char *name, type_t type)
{
	if (table->ncols < MAX_COLS)
	{
		table->cols[table->ncols].col_name = strdup(name);
		table->cols[table->ncols].type = type;
		table->ncols++;
	}
}

void add_row(table_t *table, val_t *vals)
{
	table->nrows++;
	table->rows = realloc(table->rows, sizeof(row_t) * table->nrows);
	table->rows[table->nrows - 1].val = malloc(sizeof(val_t) * table->ncols);
	for (size_t i = 0; i < table->ncols; i++)
	{
		table->rows[table->nrows - 1].val[i] = vals[i];
		// memcpy(table->rows[table->nrows-1].val, vals, sizeof(val_t));
		if (table->cols[i].type == STRING && vals[i].string != NULL)
		{
			table->rows[table->nrows - 1].val[i].string = strdup(vals[i].string);
		}
	}
}

/*void destroy_rows(row_t *rows){
}*/
void destroy_table(table_t *table)
{
	for (size_t i = 0; i < table->nrows; i++)
	{
		for (size_t j = 0; j < table->ncols; j++)
		{
			if (table->cols[j].type == STRING && table->rows[i].val[j].string != NULL)
			{
				free(table->rows[i].val[j].string);
			}
		}
		free(table->rows[i].val);
	}
	for (size_t i = 0; i < table->ncols; i++)
	{
		free(table->cols[i].col_name);
	}
	free(table->cols);
	free(table->rows);
	free(table->table_name);
	free(table);
}

// #define LEN	20
void print(table_t *table)
{
	char *headers[MAX_COLUMNS];
	for (size_t i = 0; i < table->ncols; i++)
	{
    size_t len = strlen(table->cols[i].col_name) + 1;
		headers[i] = malloc(len);
	  //snprintf(headers[i], len, "%s", table->cols[i].col_name);
	  strcpy(headers[i], table->cols[i].col_name);
  }
	char *data[MAX_COLUMNS][MAX_COLUMNS];

	for (size_t i = 0; i < table->nrows; i++)
	{
		for (size_t j = 0; j < table->ncols; j++)
		{
			data[i][j] = malloc(MAX_COLUMNS_WIDTH);
			if (data[i][j])
			{
				if (table->cols[j].type == INT)
					snprintf(data[i][j], MAX_COLUMNS_WIDTH, "%d", table->rows[i].val[j].i);
				else if (table->cols[j].type == FLOAT)
					snprintf(data[i][j], MAX_COLUMNS_WIDTH, "%f", table->rows[i].val[j].f);
				else if (table->cols[j].type == CHAR)
					snprintf(data[i][j], MAX_COLUMNS_WIDTH, "%c", table->rows[i].val[j].c);
				else if (table->cols[j].type == STRING)
					snprintf(data[i][j], MAX_COLUMNS_WIDTH, "%s", table->rows[i].val[j].string);
			}
		}
	}

	print_table((const char **)headers, table->ncols, data, table->nrows);
	for (size_t i = 0; i < table->ncols; i++)
		free(headers[i]);
	for (size_t i = 0; i < table->nrows; i++)
		for (size_t j = 0; j < table->ncols; j++)
			free(data[i][j]);
}
