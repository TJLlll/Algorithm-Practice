#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* 原地删除数组中等于目标数字的元素 */
void eliminateNum(int* arr, int size, int* getSize, int targetNum)
{
    int idx1, idx2 = 0;

    for (idx1 = 0; idx1 < size; idx1++)
    {
        if (arr[idx1] != targetNum)
        {
            /* 如果当前元素不等于目标数字，将其移到数组的前部 */ 
            /* 注意这里不再使用额外的数组，而是在原地进行操作 */ 
            arr[idx2++] = arr[idx1];
        }
    }

    *getSize = idx2; /* 更新修改后的数组大小 */ 
}

int main()
{
    srand(time(NULL));

    int getSize;
    int size = rand() % 10 + 1;
    int targetNum = rand() % 10 + 1;
    printf("生成的目标数为：%d\n", targetNum);
    int* arr = malloc(size * sizeof(int));

    /* 随机生成数组元素 */ 
    for (int idx1 = 0; idx1 < size; idx1++)
    {
        arr[idx1] = rand() % 10 + 1;
    }

    /* 输出原始数组 */ 
    printf("原始数组: ");
    for (int idx = 0; idx < size; idx++)
    {
        printf("%d ", arr[idx]);
    }
    printf("\n");

    /* 原地删除等于目标数字的元素 */ 
    eliminateNum(arr, size, &getSize, targetNum);

    /* 输出修改后的数组 */ 
    printf("删除%d后的数组: ", targetNum);
    for (int idx = 0; idx < getSize; idx++)
    {
        printf("%d ", arr[idx]);
    }
    printf("\n");

    free(arr);
    return 0;
}
