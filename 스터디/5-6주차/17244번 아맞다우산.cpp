#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;
char house[51][51];
int visited[51][51] = {0};
vector<pair<int, int>> goal;
queue<pair<int, int>> que;
int answer = INT_MAX;

bool Chk(int x, int y);
void Bfs(pair<int, int>, pair<int, int>);
int main(void)
{
    cin >> N >> M;
    pair<int, int> _start;
    pair<int, int> _end;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> house[i][j];
            if(house[i][j] == 'S') _start = make_pair(i, j);
            if(house[i][j] == 'X') goal.push_back(make_pair(i, j));
            if(house[i][j] == 'E') _end = make_pair(i, j);
        }
    }
    
    Bfs(_start, _end);

    cout << answer;
    system("pause");
    return 0;
}

void Bfs(pair<int, int> _start, pair<int, int> _end)
{
    do
    {
        int temp = 0;
        int perIndex = 0;
        int goalSize = goal.size();
        visited[_start.first][_start.second] = 1;
        que.push(_start);
        for(; perIndex < goalSize; perIndex++)
        {
            int cnt = 0;
            while(que.empty() != true)
            {
                int queSize = que.size();
                for(int q = 0; q < queSize; q++)
                {
                    int x = que.front().first;
                    int y = que.front().second;
                    que.pop();

                    if(x == goal[perIndex].first && y == goal[perIndex].second)
                    {
                        temp += cnt;
                        fill_n(visited[0], 50*50, 0);
                        while(que.empty() != true) que.pop();
                        break;
                    }

                    for(int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if(Chk(nx, ny) && visited[nx][ny] == 0 && house[nx][ny] != '#')
                        {
                            visited[nx][ny] = 1;
                            que.push(make_pair(nx, ny));
                        }
                    }
                }
                cnt++;
            }
            visited[goal[perIndex].first][goal[perIndex].second] = 1;
            que.push(make_pair(goal[perIndex].first, goal[perIndex].second));
        }

        int cnt = 0;
        while(que.empty() != true)
        {
            int queSize = que.size();
            for(int q = 0; q < queSize; q++)
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                if(x == _end.first && y == _end.second)
                {
                    temp += cnt;
                    while(que.empty() != true) que.pop();
                    fill_n(visited[0], 50*50, 0);
                    break;
                }
                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(Chk(nx, ny) && visited[nx][ny] == 0 && house[nx][ny] != '#')
                    {
                        visited[nx][ny] = 1;
                        que.push(make_pair(nx, ny));
                    }
                }

            }
            cnt++;
        }
        answer = min(answer, temp);
    } while(next_permutation(goal.begin(), goal.end()));
    
}
bool Chk(int x, int y)
{
    if(x >= 0 && x <= M-1 && y >= 0 && y <= N-1) return true;
    else return false;
}