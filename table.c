#include "db.c"
// #include "ascii_db/ascii_table.c"
#include <stdio.h>
void print(table_t *table){
	char* headers[MAX_COLUMNS];
	for (size_t i = 0; i < table->ncols; i++){
		headers[i]	= malloc(sizeof(char)*MAX_COLUMNS);
		strcpy(headers[i], table->cols[i].col_name);
	}
	char *data[MAX_COLUMNS][MAX_COLUMNS];

	for (size_t i = 0; i < table->nrows; i++){
		for (size_t j = 0; j < table->ncols; j++){
			data[i][j] = malloc(MAX_COLUMNS_WIDTH);
			if (data[i][j]){
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

	print_table((const char**)headers, table->ncols, data, table->nrows);
	for (size_t i = 0; i < table->ncols; i++)	free(headers[i]);
	for (size_t i = 0; i < table->nrows; i++)	for (size_t j = 0; j < table->ncols; j++)	free(data[i][j]);
}
