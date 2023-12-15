#include <stdio.h>
#include <stdlib.h>
#include "arrayPermutation.h"
#define ROWS        4
#define COLUMNS     4

int main() 
{
    /* 行列数据组初始化 */
    int row = ROWS;
    int colm = COLUMNS;
    int** arr = { 0 };

    arr = giveArrayNumbers(arr, &row, &colm);/* 创建二维数组并分配空间 */

    printf("数组中的数为: \n");

    printfArray(arr, &row, &colm);

    doubleArrayExchange(arr, &row, &colm);/* 行列置换 */

    printf("更改后数组中的数为: \n");

    printfArray(arr, &row, &colm);/* 打印数组的函数 */

    freeMemory(arr, &row);/* 释放内存的函数 */
    
    return 0;
    
}
