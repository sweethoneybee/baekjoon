#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10
int arr[MAX_NUM];

void check_sorted(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *A, int start, int middle, int end)
{
    int i, j, k, n1, n2;
    n1 = middle - start + 1;
    n2 = end - middle;
    int *L = (int*)malloc(sizeof(int) * (n1 + 1));
    int *R = (int*)malloc(sizeof(int) * (n2 + 1));
    
    for(i = 0; i < n1; i++)
    {
        L[i] = A[start + i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = A[middle + j + 1];
    }
    L[n1] = 200000000;
    R[n2] = 200000000;
    i = 0;
    j = 0;

    for(k = start; k <= end; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }

    free(L);
    free(R);
    return;
}

void mergeSort(int *arr, int start, int end)
{
    if(start < end)
    {
        int middle;
        middle = (start + end) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle+1, end);
        merge(arr, start, middle, end);
    }
}
int main(void)
{
    srand((unsigned int)time(NULL));
    const int n = MAX_NUM;
    int i;

    // for(i = 0; i < n; i++)
    //     arr[i] = i;
    // for(i = n - 1; i >= 1; i--)
    // {
    //     int j = rand() % (i + 1);
    //     int t = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = t;
    // }

    arr[0] = 10;
    arr[1] = 9;
    arr[2] = 8;
    arr[3] = 7;
    arr[4] = 6;
    arr[5] = 5;
    arr[6] = 4;
    arr[7] = 3;
    arr[8] = 2;
    arr[9] = 1;
    
    check_sorted(n);
    printf("Sorting %d elements...\n", n);

    mergeSort(arr, 0, n-1);

    check_sorted(n);

    printf("Ok %d elements sorted\n", n);
    system("pause");
    return 0;
}