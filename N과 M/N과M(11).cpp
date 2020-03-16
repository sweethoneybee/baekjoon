#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> chk;
bool makeHash(int answer[], int pickLimit);
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


bool makeHash(int answer[], int pickLimit)
{
    int i = 1;
    int sum = 0;
    while(pickLimit != 0)
    {
        sum += answer[pickLimit-1] * i;
        i *= 10;
        pickLimit--;
    }

    if(chk[sum] == 0)
    {
        chk[sum] += 1;
        return true;
    }
    else
    {
        return false;
    }
    
}

void Dfs(int start, int size, int count, int pickLimit, int arr[], int answer[])
{
    if(count >= pickLimit)
    {
        if(makeHash(answer, pickLimit))
        {
            for(int i = 0; i < pickLimit; i++)
            {
                cout << answer[i] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        for(int i = start; i < size; i++)
        {
            answer[count] = arr[i];
            Dfs(start, size, count + 1, pickLimit, arr, answer);
        }
    }
    
}