#ifndef __ARRAY_PERMUTATION_H
#define __ARRAY_PERMUTATION_H

#include <stdio.h>
#define ROWS        4
#define COLUMNS     4

void doubleArrayExchange(int **arr, int *row, int *colm);

void printfArray(int** arr, int* row, int* colm);

int** giveArrayNumbers(int** arr, int* row, int* colm);

void freeMemory(int** arr, int* row);

#endif