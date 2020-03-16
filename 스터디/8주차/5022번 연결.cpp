#include <iostream>
#include <queue>
using namespace std;

bool Chk(int x, int y);
void Bfs();

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;
queue<pair<int, int>> que;
priority_queue<int, vector<int>, greater<int>> pq;
int visited[101][101] = {0};
int distance = 0;
pair<int, int> A1;
pair<int, int> A2;
pair<int, int> B1;
pair<int, int> B2;

int main(void)
{
    cin >> N >> M;
    cin >> A1.first >> A1.second;
    cin >> A2.first >> A2.second;
    cin >> B1.first >> B1.second;
    cin >> B2.first >> B2.second;

    int t_count = abs(A1.first - A2.first) + abs(A1.second - A2.second);
    int i = min(A1.first, A2.first);
    int j = min(A1.second, A2.second);
    for(;j <= max(A1.second, A2.second); j++)
    {
        visited[i][j] = 1;
    }
    j--;
    for(;i <= max(A1.first, A2.first); i++)
    {
        visited[i][j] = 1;
    }
    i--;

    if(visited[B1.first][B1.second] == 0 && visited[B2.first][B2.second] == 0)
    {
        cout << "ÀÛµ¿!\n";
        que.push(B1);
        visited[B1.first][B1.second] = 1;
        Bfs();
        if(visited[B2.first][B2.second] != 0)
        {
            t_count = visited[B2.first][B2.second] + t_count - 1;
            pq.push(t_count);
        }
    }

    while(que.empty() != true) que.pop();
    t_count = abs(A1.first - A2.first) + abs(A1.second - A2.second);
    fill_n(visited[0], 101*101, 0);
    
    i = min(A1.first, A2.first);
    j = min(A1.second, A2.second);
    for(;i <= max(A1.first, A2.first); i++)
    {
        visited[i][j] = 1;
    }
    i--;
    for(;j <= max(A1.second, A2.second); j++)
    {
        visited[i][j] = 1;
    }
    j--;

    if(visited[B1.first][B1.second] == 0 && visited[B2.first][B2.second] == 0)
    {
        cout << "ÀÛµ¿!2\n";
        que.push(B1);
        visited[B1.first][B1.second] = 1;
        Bfs();
        if(visited[B2.first][B2.second] != 0)
        {
            t_count = visited[B2.first][B2.second] + t_count - 1; // B1 Àê ¶§ ´õÇÑ °Í »­
            pq.push(t_count);
        }
    }
    

    if(pq.empty() == true)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << pq.top();
    }
    
    system("pause");
    return 0;
}


bool Chk(int x, int y)
{
    if(x >= 0 && x <= N && y>= 0 && y<=M) return true;
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

            if(Chk(nx, ny) && visited[nx][ny] == 0)
            {
                visited[nx][ny] = visited[x][y] + 1;
                que.push(make_pair(nx, ny));
            }
        }

    }
}