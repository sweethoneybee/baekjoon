#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int R, C;
int miro[1000][1000] = {0};
int visited[1000][1000]= {0};
bool escape = false;
int time = 0;
queue<pair<int, int>> que;
queue<pair<int, int>> queF;
bool chk(int x, int y);
void bfs();

int main(void)
{
    cin >> R >> C;
    string input;
    for(int i = 0; i < R; ++i)
    {
        cin >> input;
        for(int j = 0; j < C; ++j)
        {
            miro[i][j] = input[j];
            if(miro[i][j] == 'J')
            {
                visited[i][j] = 1;
                que.push(make_pair(i, j));
            }
            if(miro[i][j] == 'F')
            {
                queF.push(make_pair(i, j));
            }
        }
    }

    bfs();

    if(escape == true)
    {
        cout << time;
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    
    system("pause");
    return 0;
}

bool chk(int x, int y)
{
    if(x>=0 && x<=R-1 && y>=0 && y<=C-1) return true;
    return false;
}

void bfs()
{
    int t = 0;
    while(que.empty()!=true)
    {
        ++t;
        for(int s = 0, size = queF.size(); s < size; ++s)
        {
            int x = queF.front().first;
            int y = queF.front().second;
            queF.pop();
            for(int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(chk(nx, ny) && miro[nx][ny] != 'F' && miro[nx][ny] != '#')
                {
                    miro[nx][ny] = 'F';
                    queF.push(make_pair(nx, ny));
                }
            }
        }
        for(int s = 0, size = que.size(); s < size; ++s)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(!chk(nx, ny))
                {
                    escape = true;
                    time = t;
                    return;
                }

                if(chk(nx, ny) && miro[nx][ny] == '.' && visited[nx][ny] == 0)
                {
                    visited[nx][ny] = 1;
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }
}