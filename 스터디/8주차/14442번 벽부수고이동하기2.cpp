#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> que;
queue<pair<int, int>> dist;
int N, M, K;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int map[1000][1000] = {0};
int visited[1000][1000][11] = {0};
bool Chk(int, int);
void Bfs();
int answer =  200000000;

int main(void)
{
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        for(int j = 0; j < M; j++)
        {
            map[i][j] = a[j] - '0'; 
        }
    }

    que.push(make_pair(0, 0));
    dist.push(make_pair(K, 1));
    visited[0][0][K] = 1;
    Bfs();

    
    if(answer == 200000000)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
    

    
    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x >= 0 && x <= N-1 && y>=0 && y<= M-1) return true;
    else return false;
}

void Bfs()
{
    while(que.empty() != true)
    {
        int x = que.front().first;
        int y = que.front().second;
        int wall = dist.front().first;
        int dis = dist.front().second;
        que.pop(); dist.pop();

        if(x == N-1 && y == M-1)
        {
            if(dis < answer)
            {
                answer = dis;
            }
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!Chk(nx, ny)) continue;

            if(map[nx][ny] == 0 && visited[nx][ny][wall] == 0)
            {
                visited[nx][ny][wall] = 1;
                que.push(make_pair(nx, ny));
                dist.push(make_pair(wall, dis+1));
            }
            else if(map[nx][ny] == 1)
            {
                if(wall > 0 && visited[nx][ny][wall] == 0)
                {
                    visited[nx][ny][wall] = 1;
                    que.push(make_pair(nx, ny));
                    dist.push(make_pair(wall -1, dis+1));
                }
            }
        }
    }

    return;
}

