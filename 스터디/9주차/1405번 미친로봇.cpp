#include <iostream>
using namespace std;

long double answer;
long double percent[4] = {0};
bool visited[30][30] = {0};
int N;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int, int, int, long double);
int main(void)
{
    cin >> N;
    for(int i = 0; i < 4; i++)
    {
        cin >> percent[i];
        percent[i] *= 0.01;
    }
    
    answer = 0;
    visited[15][15] = 1;
    dfs(15, 15, 0, 1);
    
    cout.setf(ios::fixed);
    cout.precision(9);
    cout << answer;

    cout.unsetf(ios::fixed);
    system("pause");
    return 0;
}

void dfs(int x, int y, int n, long double prob)
{
    if(n == N)
    {
        answer += prob;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(visited[x + dx[i]][y + dy[i]] == 0)
        {
            visited[x + dx[i]][y + dy[i]] = 1;
            dfs(x + dx[i], y + dy[i], n + 1, prob * percent[i]);
            visited[x + dx[i]][y + dy[i]] = 0;
        }
    }
    return;
}