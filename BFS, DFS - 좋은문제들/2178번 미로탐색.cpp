#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int miro[101][101] = {0};
int answer[101][101] = {0};
queue<pair<int, int>> que;
int N, M;

void Bfs();
bool Chk(int x, int y);

int main(void)
{
    cin >> N >> M;
    string input;
    

  
    for(int i = 1; i <= N; i++)
    {
        cin >> input;

        for(int j = 0; j < input.length(); j++)
        {
            miro[i][j+1] = input[j] -'0';
        }
    }

    que.push(make_pair(1, 1));
    miro[1][1] = -1;
    Bfs();

    cout << answer[N][M] + 1;
    system("pause");
    return 0;
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

            if(Chk(nx, ny) && miro[nx][ny] == 1)
            {
                que.push(make_pair(nx, ny));
                miro[nx][ny] = -1;
                answer[nx][ny] = answer[x][y] + 1;
            }
        }
    }
}

bool Chk(int x, int y)
{
    if( x >= 1 && x <= N && y >= 1 && y <= M)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}