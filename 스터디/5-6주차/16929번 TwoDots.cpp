#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<pair<int, int>> que;
queue<pair<int, int>> from;
int N, M;
int answer = 0;

int game[50][50] = {0};
int visited[50][50] = {0};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool Chk(int x, int y);
void Bfs(int word);
int main(void)
{    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        string a;
        cin >> a;

        for(int j = 0; j < a.size(); j++)
        {
            game[i][j] = a[j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(visited[i][j] == 0)
            {
                int word = game[i][j];
                visited[i][j] = 1;
            
                que.push(make_pair(i, j));
                from.push(make_pair(-1, -1));
                Bfs(word);
            }

        }
    }

    if(answer == 1) cout << "Yes";
    else cout << "No";

    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if( x >= 0 && x <= N-1 && y >= 0 && y<= M-1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Bfs(int word)
{
    while(que.empty() != true)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        int fromX = from.front().first;
        int fromY = from.front().second;
        from.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(Chk(nx, ny) && game[nx][ny] == word)
            {
                if(visited[nx][ny] == 0)
                {
                    visited[nx][ny] = 1;
                    que.push(make_pair(nx, ny));               
                    from.push(make_pair(x, y));
                }
                else if(visited[nx][ny] == 1 && nx != fromX && ny != fromY)
                {
                    answer = 1;
                    return;
                }
            }
        }
    }

}
