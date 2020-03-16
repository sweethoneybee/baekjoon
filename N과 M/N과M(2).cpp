#include <iostream>
using namespace std;

void com(int start, int size, int count, int m, int arr[]);
int main(void)
{
    int N, M;
    cin >> N >> M;
    int* arr = new int[N];

    com(0, N, 0, M, arr);

    delete[] arr;
    system("pause");
    return 0;
}

void com(int start, int size, int count, int m, int arr[])
{
    if(count >= m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i = start; i < size; i++)
        {
            arr[count] = i+1;
            com(i + 1, size, count + 1, m, arr);
        }
    }
    
}