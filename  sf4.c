#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int size)
{
    for(int idx1 = 0; idx1 < size - 1; idx1++)
    {
        int minnum = arr[idx1 + 1];
        for(int idx2 = idx1 + 2; idx2 < size; idx2++)
        {
            if(arr[idx2] < minnum)
            {
                swap(&arr[idx1 + 1], &arr[idx2]);
            }
        }

        if(arr[idx1] < minnum)
        {
            swap(&arr[idx1], &arr[idx1 + 1]);
        }
    }
}






int main() 
{
    int arr1[] = {8, 2, 4, 3, 4, 7, 6, 4, 1, 7, 99, 9999999999};
    int size = sizeof(arr1) / sizeof(arr1[0]); 
    sort(arr1, size);
    for(int idx = 0; idx < size; idx++)
    {
        printf("%d ", arr1[idx]);
    }
    printf("\n");
    return 0;
}
