#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
int arr[100001] = {0};
int from[100001] = {0};
int answer = 0;

queue<int> que;
vector<int> vec;
void bfs();
int main(void)
{
    cin >> N >> K;
    fill_n(arr, 100001, 1000000);
    arr[N] = 0;

    que.push(N);
    bfs();

    answer = arr[K];
    vec.push_back(K);
    int temp = K;
    while(temp != N)
    {
        temp = from[temp];
        vec.push_back(temp);   
    }
    cout << answer << endl;
    for(auto i = vec.rbegin(), end = vec.rend(); i != end; i++)
    {
        cout << *i << " ";
    }
    system("pause");
    return 0;
}

void bfs()
{
    while(que.empty() != true)
    {
        int x = que.front();
        que.pop();

        if(x + 1 <= 100000 && arr[x] + 1< arr[x+1])
        {
            arr[x + 1] = arr[x] + 1;
            from[x + 1] = x;
            que.push(x+1);
        }
        if(x - 1 >= 0 && arr[x] + 1 < arr[x - 1])
        {
            arr[x - 1] = arr[x] + 1;
            from[x - 1] = x;
            que.push(x - 1);
        }

        if(x * 2 <= 100000 && arr[x] + 1 < arr[x * 2])
        {
            arr[x * 2] = arr[x] + 1;
            from[x * 2] = x;
            que.push(x * 2);
        }
    }
}