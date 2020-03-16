#include <iostream>
#include <algorithm>
using namespace std;

void Dfs(int count, int size, int m, int chk[], int per[], int arr[]);
int main(void)
{
    int N, M;
    cin >> N >> M;
    
    int* arr = new int[N];
    int* chk = new int[N];
    int* per = new int[N];
    for(int i = 1; i <= N; i++)
    {
        arr[i-1] = i;
        chk[i-1] = 0;
    }

    Dfs(0, N, M, chk, per, arr);


    delete[] arr;
    delete[] chk;
    delete[] per;
    system("pause");
    return 0;
}

void Dfs(int count, int size, int m, int chk[], int per[], int arr[])
{
    if(count >= m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << per[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            if(chk[i] == 0)
            {
                chk[i] = 1;
                per[count] = arr[i];
                Dfs(count + 1, size, m, chk, per, arr);
                chk[i] = 0;
            }
        }
    }
    
}