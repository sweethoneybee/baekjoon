#include <iostream>
#include <algorithm>
using namespace std;


void Dfs(int start, int size, int count, int pickLimit, int arr[], int answer[]);
int main(void)
{
    int N, M;
    cin >> N >> M;
    int *arr = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int *answer = new int[N];
    Dfs(0, N, 0, M, arr, answer);
    delete[] arr;
    delete[] answer;
    system("pause");
    return 0;
}


void Dfs(int start, int size, int count, int pickLimit, int arr[], int answer[])
{
    if(count >= pickLimit)
    {
        for(int i = 0; i < pickLimit; i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = start; i < size; i++)
        {
            answer[count] = arr[i];
            Dfs(i + 1, size, count+1, pickLimit, arr, answer);
        }
    }
    
}