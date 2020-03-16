#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> que;
vector<int> width;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int graph[100][100] = {0};
int M, N, K;


int Bfs();
bool Chk(int x, int y);
int main(void)
{
    cin >> M >> N >> K;
    
    int a, b, c, d;
    for(int k = 0; k < K; k++)
    {
        cin >> a >> b >> c >> d;
        for(int i = a; i < c; i++)
        {
            for(int j = b; j < d; j++)
            {
                graph[i][j] = -1;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(graph[i][j] == 0)
            {
                que.push(make_pair(i, j));
                graph[i][j] = -1;
                count++;
                int t_width = Bfs();
                width.push_back(t_width);
            }
        }
    }

    sort(width.begin(), width.end(), less<int>());
    cout << count << "\n";
    for(auto i = width.begin(); i != width.end(); i++)
    {
        cout << *i << " ";
    }

    system("pause");
    return 0;
}

int Bfs()
{
    int width = 0;
    while(que.empty() != true)
    {
        width++;
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(Chk(nx, ny) && graph[nx][ny] == 0)
            {
                que.push(make_pair(nx, ny));
                graph[nx][ny] = -1;
            }
        }
    }

    return width;
}

bool Chk(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y< M)
    {
        return true;
    }
    else
    {
        return false;
    }
}