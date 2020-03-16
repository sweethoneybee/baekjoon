#include <iostream>
using namespace std;

void Dfs(int start, int size, int count, int pickLimit, int arr[]);
int main(void)
{
    int N, M;
    cin >> N >> M;
    int *arr = new int[N];

    Dfs(0, N, 0, M, arr);

    delete[] arr;
    system("pause");
    return 0;
}

void Dfs(int start, int size, int count, int pickLimit, int arr[])
{
    if(count >= pickLimit)
    {
        for(int i = 0; i < pickLimit; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = start; i < size; i++)
        {
            if(i >= start)
            {
                arr[count] = i + 1;
                Dfs(i, size, count + 1, pickLimit, arr);
            }
        }
    }
}