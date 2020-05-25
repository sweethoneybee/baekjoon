#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int N;
pair<int, int> answer;
int main(void)
{
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    
    int front = 0;
    int rear = N - 1;
    int min = arr[front] + arr[rear];
    answer.first = arr[front];
    answer.second = arr[rear];
    for(; front < rear;)
    {
        int sum = arr[front] + arr[rear];
        if(abs(sum) < abs(min))
        {
            min = sum;
            answer.first = arr[front];
            answer.second = arr[rear];
        }
        if(sum == 0)
            break;
        else if(sum < 0)
        {
            ++front;
        }
        else
        {
            --rear;
        }
        
    }

    cout << answer.first << " " << answer.second;
    system("pause");
    return 0;
}