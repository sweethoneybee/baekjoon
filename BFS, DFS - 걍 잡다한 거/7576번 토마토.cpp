#include <iostream>
#include <queue>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;
queue<pair<int, int>> que;
int countDay = 0;

int tomato[1000][1000] = {0};
bool visited[1000][1000] ={0};

bool Chk(int, int);
void Bfs();

int main(void)
{
    cin >> M >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0 ; j < M; j++)
        {
            cin >> tomato[i][j];
            if(tomato[i][j] == 1)
            {
                que.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }

    Bfs();
    
    bool all = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(tomato[i][j] == 0)
            {
                all = 0;
                i = N;
                break;
            }
        }
    }

    if(all == 1) cout << countDay;
    else cout << -1;

    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x>=0 && x<=N-1 && y>=0 && y<=M-1) return true;
    else return false;
}

void Bfs()
{
    int count = 0;
    while(que.empty() != true)
    {
        int queSize = que.size();
        for(int q = 0; q < queSize; q++)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(Chk(nx, ny) && visited[nx][ny] == 0 && tomato[nx][ny] == 0)
                {
                    que.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                    tomato[nx][ny] = 1;
                }
            }
        }
        count++;
    }

    countDay = count - 1;
}
