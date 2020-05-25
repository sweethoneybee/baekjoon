#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int visited[10001] = {0};
int prime[10001] = {0};
int T, answer;
queue<pair<int, int>> que;

void bfs(int target);
int main(void)
{
    // if prime, prime[n] == 0;
    prime[1] = 1;
    for(int i = 2; i <= sqrt(10000.0); i++)
    {
        if(prime[i] == 0)
        {
            for(int m = 2; i * m <= 10000; m++)
            {
                prime[i * m] = 1;
            }
        }
    }

    cin >> T;
    for(int t = 0; t < T; t++)
    {
        fill_n(visited, 10001, 0);
        answer = -1;
        while(que.empty() != true)
        {
            que.pop();
        }
        int num, target;
        cin >> num >> target;

        que.push(make_pair(num, 0));
        visited[num] = 1;
        bfs(target);

        if(answer == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << answer << endl;
        }
    }


    system("pause");
    return 0;
}

void bfs(int target)
{
    while(que.empty() != true)
    {
        int num = que.front().first;
        int cnt = que.front().second;
        que.pop();
        if(num == target)
        {
            answer = cnt;
            break;
        } 

        int d[4] = {0};
        int temp = num;
        int idx = 3;
        while(temp > 0)
        {
            d[idx] = temp % 10;
            temp /= 10;
            idx--;
        }

        for(int i = 1; i <= 9; i++)
        {
            temp = i * 1000 + d[1] * 100 + d[2] * 10 + d[3] * 1;
            if(prime[temp] == 0 && visited[temp] == 0)
            {
                visited[temp] = 1;
                que.push(make_pair(temp, cnt + 1));
            }
        }
        for(int i = 0; i <= 9; i++)
        {
            temp = 1000 * d[0] + i * 100 + d[2] * 10 + d[3] * 1;
            if(prime[temp] == 0 && visited[temp] == 0)
            {
                visited[temp] = 1;
                que.push(make_pair(temp, cnt + 1));
            }
        }
        for(int i = 0; i <= 9; i++)
        {
            temp = 1000 * d[0] + d[1] * 100 + i * 10 + d[3] * 1;
            if(prime[temp] == 0 && visited[temp] == 0)
            {
                visited[temp] = 1;
                que.push(make_pair(temp, cnt + 1));
            }
        }
        for(int i = 0; i <= 9; i++)
        {
            temp = 1000 * d[0] + d[1] * 100 + d[2] * 10 + i * 1;
            if(prime[temp] == 0 && visited[temp] == 0)
            {
                visited[temp] = 1;
                que.push(make_pair(temp, cnt + 1));
            }
        }
    }
}