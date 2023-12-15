#include <stdio.h>
#include <stdlib.h>
#include "arrayPermutation.h"

void doubleArrayExchange(int **arr, int* row, int* colm)
{
    for(int idx1 = 0; idx1 < *row; idx1++) 
    {
        for(int idx2 = idx1 + 1; idx2 < *colm; idx2++) /* !!! */
        {
            int temp = *(*(arr + idx1) + idx2);
            *(*(arr + idx1) + idx2) = *(*(arr + idx2) + idx1);
            *(*(arr + idx2) + idx1) = temp;
        }
    }


    
}

void printfArray(int** arr, int* row, int* colm)
{
    for(int idx1 = 0; idx1 < *row; idx1++) 
    {
        for(int idx2 = 0; idx2 < *colm; idx2++) 
        {
            printf("%d ", *(*(arr + idx1) + idx2));
        }
        printf("\n");
    }

}

int** giveArrayNumbers(int** arr, int* row, int* colm)
{
    printf("请输入数组中的数: \n");
    arr = (int **)malloc(*row * sizeof(int *));
  
    for(int idx1 = 0; idx1 < *row; idx1++) 
    {
        *(arr + idx1) = (int *)malloc(*colm * sizeof(int));

        for(int idx2 = 0; idx2 < *colm; idx2++) 
        {
            scanf("%d", (*(arr + idx1) + idx2));
        }
    }
    return arr;
}

void freeMemory(int** arr, int* row)
{
        for(int idx1 = 0; idx1 < *row; idx1++) 
    {
        free(*(arr + idx1));
    }
    free(arr);
}