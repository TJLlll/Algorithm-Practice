#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
    int index1;
    int index2;
} Indices;

Indices* findTwoSum(int array[], int size, int targetNum) 
{
    Indices* result = malloc(sizeof(Indices));  /* 声明一个结构体指针 */
    if (result == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = i + 1; j < size; ++j) 
        {
            if (array[i] + array[j] == targetNum) 
            {
                result->index1 = i;     /* 通过结构体指针访问结构体变量 */
                result->index2 = j;
                return result;     /* 找到符合条件的数返回指针result并退出 */
            }
        }
    }

    free(result);   /* 未找到符合条件的数则释放给result分配的内存，并返回NULL */
    return NULL;
}

int main() 
{
    srand(time(NULL));

    /* 生成随机大小的数组 */
    int size = rand() % 100 + 1; 
    int* array = malloc(size * sizeof(int));  /* 此处(size * sizeof(int)中的*为乘的意思，意为给array数组分配size个int大小的内存空间，并将首地址给array */
    if (array == NULL) 
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    /* 随机生成数组中的数 */
    for (int i = 0; i < size; ++i) 
    {
        array[i] = rand() % 100 + 1;
    }

    /* 给定目标数 */
    int targetNum = rand() % 100 + 1;
    printf("Generated array:\n");
    for (int idx = 0; idx < size; ++idx) 
    {
        printf("%d ", array[idx]);
    }
    printf("\nTarget number: %d\n", targetNum);

    /* 在数组中找出两个数相加等于目标数 */ 
    Indices* result = findTwoSum(array, size, targetNum);

    /* 输出结果 */
    if (result != NULL) /* 判断函数返回值是否为NULL，不为NULL则返回了指针result说明找到符合的两个数 */
    {
        printf("Indices of two numbers: %d, %d\n", result->index1, result->index2);
        free(result);       /* 输出完后释放indices结构体类型指针result */
    } 
    else 
    {
        printf("No such indices found.\n");
    }

    /* 释放数组内存 */
    free(array);

    return 0;
}