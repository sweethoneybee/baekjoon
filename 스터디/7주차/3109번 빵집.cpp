#include <iostream>
#include <string>

using namespace std;

int R, C;
int dx[] = {-1, 0, 1};
int dy[] = {1, 1, 1};
bool Chk(int x, int y);
void Dfs(int x, int y, int cnt);
bool visited[10000][500] = {0};
char map[10000][501] = {0};
int answer = 0;
bool chk = false;
int main(void)
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < R; i++)
    {
        cout << "start visit : " << i << " , " << 0 << endl;
        chk = false;
        Dfs(i, 0, 1);
    }

    cout << answer;
    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x >= 0 && x <= R-1 && y>=0 && y<=C-1) return true;
    else return false;
}

void Dfs(int x, int y, int cnt)
{
    //cout << "dfs called\n";
    if(y == C-1)
    {
        answer++;
        chk = true;
    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(Chk(nx, ny) && map[nx][ny] != 'x' && visited[nx][ny] == 0 && chk == false )
            {
                cout << "visit : " << nx << " , " << ny << endl;
                visited[nx][ny] = 1;
                Dfs(nx, ny, cnt+1);
                
            }
        }
    }
}