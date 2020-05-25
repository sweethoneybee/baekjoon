#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
int main(void)
{
    scanf("%d", &N);
    int temp;
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &temp);
        pq.push(temp);
    }
    
    int a, b;
    int sum = 0;
    for(int i = 0; i < N - 1; i++)
    {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();

        temp = a + b;
        sum += temp;

        pq.push(temp);
    }

    cout << sum;
    system("pause");
    return 0;
}