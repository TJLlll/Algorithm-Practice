#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int* mergeOderNum(int *num1, int num1Size, int *num2, int num2Size, int *newNumSize)
{
    /* 为目标数组分配空间，并初始化为0 */
    int *newNum = (int *)malloc((*newNumSize) * sizeof(int));

    /* 数组元素复制 */
    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;
    while (idx1 < num1Size && idx2 < num2Size)
    {
        if (num1[idx1] <= num2[idx2])
        {
            newNum[idx3] = num1[idx1];
            idx1++;
        }
        else
        {
            newNum[idx3] = num2[idx2];
            idx2++;
        }
        idx3++;
    }

    /* 将有多余元素剩下的数组中的数给newNum */
    while (idx1 < num1Size)
    {
        newNum[idx3] = num1[idx1];
        idx1++;
        idx3++;
    }

    while (idx2 < num2Size)
    {
        newNum[idx3] = num2[idx2];
        idx2++;
        idx3++;
    }

    return newNum;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int size)
{
    for (int idx1 = 0; idx1 < size - 1; idx1++)
    {
        int minIdx = idx1;
        for (int idx2 = idx1 + 1; idx2 < size; idx2++)
        {
            if (arr[idx2] < arr[minIdx])
            {
                minIdx = idx2;
            }
        }
        swap(&arr[minIdx], &arr[idx1]);
    }
}

int main()
{
    srand(time(NULL));

    /* 生成两个数组元素个数随机、数组元素大小1到20以内随机的数组 */
    int num1Size = rand() % 10 + 1;
    int num2Size = rand() % 10 + 1;

    int *num1 = (int *)malloc(num1Size * sizeof(int));
    int *num2 = (int *)malloc(num2Size * sizeof(int));

    /* 对两个数组赋予大小为1到20内的随机数 */
    for (int idx = 0; idx < num1Size; idx++)
    {
        num1[idx] = rand() % 20 + 1;
    }

    /* 对数组num1排序 */
    sort(num1, num1Size);

    for (int idx = 0; idx < num2Size; idx++)
    {
        num2[idx] = rand() % 20 + 1;
    }

    /* 对数组num2排序 */
    sort(num2, num2Size);

    /* 打印出两个数组的数 */
    printf("数组1的数为: \n");
    for (int idx = 0; idx < num1Size; idx++)
    {
        printf("%d ", num1[idx]);
    }

    printf("\n数组2的数为: \n");
    for (int idx = 0; idx < num2Size; idx++)
    {
        printf("%d ", num2[idx]);
    }

    printf("\n");

    /* 计算合并后数组的大小为num1Size + num2Size */
    int newNumSize = num1Size + num2Size;

    int *newNum = mergeOderNum(num1, num1Size, num2, num2Size, &newNumSize);

    /**/
    printf("得到的数组为：\n");

    for (int idx = 0; idx < newNumSize; idx++)
    {
        printf("%d ", newNum[idx]);
    }

    printf("\n");

    /* 释放内存 */
    if (num1 != NULL && num2 != NULL && newNum != NULL)
    {
        free(num1);
        free(num2);
        free(newNum);
        num1 = NULL;
        num2 = NULL;
        newNum = NULL;
    }


    return 0;
}
