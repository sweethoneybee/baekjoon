#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool makeHash(int answer[], int pickLimit);
map<int, int> been;

void Dfs(int start, int size, int count, int pickLimit, int arr[], int answer[], int chk[]);
int main(void)
{
    int N, M;
    cin >> N >> M;
    int *arr = new int[N];
    int *chk = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        chk[i] = 0;
    }
    sort(arr, arr + N);
    int *answer = new int[N];
    
    Dfs(0, N, 0, M, arr, answer, chk);

    delete[] answer;
    delete[] arr;
    system("pause");
    return 0;
}


void Dfs(int start, int size, int count, int pickLimit, int arr[], int answer[], int chk[])
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
            if(chk[i] == 0)
            {
                answer[count] = arr[i];
                chk[i] = 1;
                Dfs(start, size, count +1, pickLimit, arr, answer, chk);
                chk[i] = 0;
            }
        }
    }
    
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

    if(been[sum] == 0)
    {
        been[sum] += 1;
        return true;
    }
    else
    {
        return false;
    }
    
}