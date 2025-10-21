#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
// #include "../table.c"
#include "ascii_table.h"
void print_table_header(const char* headers[MAX_COLUMNS], int ncols, int cols_width[MAX_COLUMNS]){
	printf("+");
	for (int i = 0; i < ncols; i++){
		for(int j = 0; j < cols_width[i] + 2; j++)	printf("-");
		printf("+");
	}
	//printf("+");
	printf("\n");

	// print columns name
	printf("|");
	for (int i = 0; i < ncols; i++){
		printf(" %-*s |", cols_width[i], headers[i]);
	}
	printf("\n");
	printf("+");
	for (int i = 0; i < ncols; i++){
		for (int j = 0; j < cols_width[i] + 2; j++){	printf("-");	}
		printf("+");
	}
	printf("\n");
}


void print_table_row(char* data[MAX_COLUMNS], int ncols, int cols_width[MAX_COLUMNS]){
	printf("|");
	for (int i = 0; i < ncols; i++){
		printf(" %-*s |", cols_width[i], data[i]);
	}
	printf("\n");
}


void print_table_footer(int ncols, int cols_width[MAX_COLUMNS]){
	printf("+");
	for (int i = 0; i < ncols; i++){
		for (int j = 0; j < cols_width[i] + 2; j++){
			printf("-");
		}
		printf("+");
	}
	printf("\n");
}


void print_table(const char *headers[MAX_COLUMNS], int ncols, char*data[MAX_COLUMNS][MAX_COLUMNS], int nrows){
	if (ncols > MAX_COLUMNS || ncols <= 0){
		return;
	}

	int cols_width[MAX_COLUMNS] = {0};
	for (int i = 0; i < ncols; i++)	{
		cols_width[i] = strlen(headers[i]);
		for (int j = 0; j < nrows; j++)	{
			int data_len = strlen(data[j][i]);
			if (data_len > cols_width[i] && data_len <= MAX_COLUMNS_WIDTH){
				cols_width[i] = data_len;
			}
		}
		if (cols_width[i] >= MAX_COLUMNS_WIDTH)	{
			cols_width[i] = MAX_COLUMNS_WIDTH;
		}
	}
	print_table_header(headers, ncols, cols_width);
	for (int i = 0; i < nrows; i++)
		print_table_row(data[i], ncols, cols_width);
	print_table_footer(ncols, cols_width);
}

// void print(table_t *table){
// 	char* headers[MAX_COLUMNS];
// 	for (size_t i = 0; i < table->ncols; i++){
// 		headers[i]	= malloc(sizeof(char)*LEN);
// 		strcpy(headers[i], table->cols[i].col_name);
// 	}
// 	char *data[MAX_COLUMNS][MAX_COLUMNS];

// 	for (size_t i = 0; i < table->nrows; i++){
// 		for (size_t j = 0; j < table->ncols; j++){
// 			data[i][j] = malloc(LEN);
// 			if (data[i][j]){
// 				if (table->cols[j].type == INT)
// 					snprintf(data[i][j], LEN, "%d", table->rows[i].val[j].i);
// 				else if (table->cols[j].type == FLOAT)
// 					snprintf(data[i][j], LEN, "%f", table->rows[i].val[j].f);
// 				else if (table->cols[j].type == CHAR)
// 					snprintf(data[i][j], LEN, "%c", table->rows[i].val[j].c);
// 				else if (table->cols[j].type == STRING)
// 					snprintf(data[i][j], LEN, "%s", table->rows[i].val[j].string);
// 			}
// 		}
// 	}

// 	print_table((const char**)headers, table->ncols, data, table->nrows);
// 	for (size_t i = 0; i < table->ncols; i++)	free(headers[i]);
// 	for (size_t i = 0; i < table->nrows; i++)	for (size_t j = 0; j < table->ncols; j++)	free(data[i][j]);
// }
