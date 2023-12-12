#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* eliminateNum(int* str, int size, int* getSize, int targetNum)
{
    int *strget = malloc(size * sizeof(int));
    int idx1, idx2 = 0;

    for (idx1 = 0; idx1 < size; idx1++)
    {
        if (str[idx1] != targetNum)
        {
            strget[idx2++] = str[idx1];
        }
    }
    *getSize = idx2; /* 将idx2,也就是消除目标数后生成数组的元素个数通过地址给getSize */
    return strget;
}

int main()
{
    srand(time(NULL));
    int getSize;  /* 消除目标后的数组元素个数 */
    int size = rand() % 10 + 1;  /* 待处理的数组的元素个数 */
    int targetNum = rand() % 10 + 1;

    printf("目标数为：%d\n", targetNum);

    int* arr = malloc(size * sizeof(int));/* 创建一个名为arr的数组，并为其分配size大小的内存空间 */  

    for (int idx1 = 0; idx1 < size; idx1++)
    {
        arr[idx1] = rand() % 10 + 1;
    }

    printf("生成的数组为：\n");

    for (int idx = 0; idx < size; idx++)
    {
        printf("%d ", arr[idx]);
    }

    printf("\n");

    int* strget = eliminateNum(arr, size, &getSize, targetNum);/* 用指针strget来接收消除目标数的函数返回的地址 */

    printf("消除targetNum后的数组为:\n");
    for (int idx = 0; idx < getSize; idx++)
    {
        printf("%d ", strget[idx]);
    }
    printf("\n");

    free(arr);
    free(strget);
    return 0;
}
