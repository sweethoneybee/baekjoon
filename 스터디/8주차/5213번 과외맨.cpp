#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int root[600][1100] = {0};
int tile[600][1100] = {0};
int visited[600][1100] = {0};
int mark[600][1100][2] = {0};
bool chk[550000] = {0};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool Chk(int, int);
void Bfs();
int N;
int Index = 1;
int max_tile = -1;
pair<int, int> max_tile_cor;
queue<pair<int, int>> que;
vector<int> answer;

int main(void)
{
    fill_n(visited[0], 500*1000, 80000000);
    cin >> N;
    for(int i = 0 ; i < N; i++)
    {
        int count = 0;
        if(i % 2 == 0)
        {
            for(int j = 0; j < N; j++)
            {
                for(int k = 0; k < 2; k++)
                {
                    cin >> root[i][j * 2 + k];
                    tile[i][j * 2 + k] = Index;
                }
                Index++;
            }
        }

        else
        {
            for(int j = 1; j < N; j++)
            {
                for(int k = 1; k >= 0; k--)
                {
                    cin >> root[i][j * 2 - k];
                    tile[i][j * 2 - k] = Index;
                }
                Index++;
            }
        }
    }

    Index--;

    visited[0][0] = 1;
    que.push(make_pair(0, 0));
    Bfs();
    
    int tempX = max_tile_cor.first;
    int tempY = max_tile_cor.second;
    
    while(tile[tempX][tempY] != 1)
    {
        if(chk[tile[tempX][tempY]] == 0)
        {
            chk[tile[tempX][tempY]] = 1;
            answer.push_back(tile[tempX][tempY]);
        }
        int t_tempX = tempX;
        tempX = mark[tempX][tempY][0];
        tempY = mark[t_tempX][tempY][1];
    }

    answer.push_back(1);
    int size = answer.size();
    cout << size << endl;
    for(auto i = answer.rbegin(); i != answer.rend(); i++)
    {
        cout << *i << " ";
    }
    
    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x >= 0 && x <= N - 1 && y>=0 && y <= N * 2 - 1) return true;
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

            if(!Chk(nx, ny)) continue;

            if(tile[x][y] != tile[nx][ny] && visited[nx][ny] >= visited[x][y] + 1 && root[x][y] == root[nx][ny])
            {
                que.push(make_pair(nx, ny));
                visited[nx][ny] = visited[x][y] + 1;
                mark[nx][ny][0] = x;
                mark[nx][ny][1] = y;

                if(max_tile <= tile[nx][ny])
                {
                    max_tile = tile[nx][ny];
                    max_tile_cor = make_pair(nx, ny);
                }
            }
            if(tile[x][y] == tile[nx][ny] && visited[nx][ny] > visited[x][y])
            {
                que.push(make_pair(nx,ny));
                visited[nx][ny] = visited[x][y];
                mark[nx][ny][0] = x;
                mark[nx][ny][1] = y;
            }

        }
    }
}
