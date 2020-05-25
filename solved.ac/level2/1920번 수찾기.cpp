#include <stdio.h>
#include <algorithm>
using namespace std;

bool find(int *arr, int key, int start, int end)
{
    if(start >= end)
        return key == arr[end];
    else
    {
        int m = (start + end) / 2;
        if(arr[m] < key)
        {
            return find(arr, key, m + 1, end);
        }
        else if(arr[m] > key)
        {
            return find(arr, key, start, m - 1);
        }
        else
        {
            return true;
        }
    }
}
int main(void)
{
    int N, M;
    scanf("%d", &N);
    
    int *arr = new int[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    scanf("%d", &M);
    for(int i = 0, temp; i < M; i++)
    {
        scanf("%d", &temp);
        if(find(arr, temp, 0, N-1) == true)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        
    }
    system("pause");
    delete[] arr;
    return 0;
}