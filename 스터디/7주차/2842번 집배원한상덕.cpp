#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
char vil[50][50];
int h[50][50];
bool visited[50][50] = {0};
int houses = 0;
int result = 3000000;
bool Chk(int, int);
int main(void)
{
    cin >> N;
    pair<int, int> _start;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> vil[i][j];
            if(vil[i][j] == 'K') houses++;
            if(vil[i][j] == 'P') _start = make_pair(i, j);
        }
    }

    vector<int> fatigue;    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> h[i][j];
            fatigue.push_back(h[i][j]);
        }
    }
    
    sort(fatigue.begin(), fatigue.end());
    fatigue.erase(unique(fatigue.begin(), fatigue.end()), fatigue.end());

   
    int low = 0; int high = 0;

    while(low < fatigue.size())
    {
        fill_n(visited[0], sizeof(visited), 0);
        queue<pair<int, int>> que;
        int piro = h[_start.first][_start.second];
        
        if(piro >= fatigue[low] && piro <=fatigue[high])
        {
            visited[_start.first][_start.second] = 1;
            que.push(_start);
        }

        int K = 0;

        while(que.empty() != true)
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(!Chk(nx, ny) || visited[nx][ny] != 0) continue;

                int piro = h[nx][ny];

                if(piro >= fatigue[low] && piro <= fatigue[high])
                {
                    visited[nx][ny] = 1;
                    que.push(make_pair(nx, ny));

                    if(vil[nx][ny] == 'K')
                    {
                        K++;
                    }
                }
            }
        }

        if(K == houses)
        {
            result = min(result, fatigue[high] - fatigue[low]);

            low++;
        }
        else if(high + 1 < fatigue.size())
        {
            high++;
        }
        else
        {
            break;
        }
        
    }

    cout << result << "\n";
    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x >= 0 && x<=N-1 && y>=0 && y<= N-1) return true;
    else return false;
}