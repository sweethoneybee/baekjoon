#include <iostream>
#include <queue>
#include <string>
using namespace std;

int miro[100][100] = {0};
int answer[100][100] = {0};
bool visited[100][100] = {0};

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void Bfs();
bool Chk(int x, int y);
int N, M;
queue<pair<int, int>> que;

int main(void)
{
    cin >> N >> M;
    for(int i = 0;i < N; i++)
    {
        string a;
        cin >> a;
        for(int j = 0; j < M; j++)
        {
            miro[i][j] = a[j];
        }
    }

    que.push(make_pair(0, 0));
    visited[0][0] = 1;
    answer[0][0] = 1;
    Bfs();

    cout << answer[N-1][M-1];

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
    while(que.empty() != true)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(Chk(nx, ny) && visited[nx][ny] == 0 && miro[nx][ny] == '1')
            {
                que.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                answer[nx][ny] = answer[x][y] + 1;
            }
        }
    }
}