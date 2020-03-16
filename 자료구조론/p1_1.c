#include <stdio.h>

void swap(int arr[], int x, int y);
void selectionSort(int arr[], int size);

int main(void)
{
    int N;
    scanf("%d", &N);

    int *arr = (int*)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, N);

    for(int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    system("pause");
    return 0;
}


void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size -1 ; i++)
    {
        int min = arr[i];
        int index = i;
        for(int j = i; j < size; j++)
        {
            if(min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }

        if(index != i)
        {
            swap(arr, index, i);
        }
    }
}