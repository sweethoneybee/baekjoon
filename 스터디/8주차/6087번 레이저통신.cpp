#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int db[] = {2, 3, 0, 1};
int map[100][100] = {0};
int visited[100][100] = {0};
priority_queue<int, vector<int>, greater<int>> pq;
queue<pair<int, int>> que;
queue<pair<int, int>> dir;
int W, H;

bool Chk(int x, int y);
void Bfs();
int main(void)
{
    cin >> W >> H;

    pair<int, int> _start;
    for(int i = 0; i < H; i++)
    {
        string a;
        cin >> a;
        for(int j = 0; j <W ; j++)
        {
            map[i][j] = a[j];
            if(map[i][j] == 'C') 
            {
                _start.first = i;
                _start.second = j;
            }
        }
    }


    fill_n(visited[0], 100*100, 10000);
    visited[_start.first][_start.second] = -1;
    for(int i = 0; i < 4; i++)
    {
        int nx = _start.first + dx[i];
        int ny = _start.second + dy[i];

        if(map[nx][ny] == 'C')
        {
            pq.push(0);
        }
        if(map[nx][ny] != '*')
        {
            que.push(make_pair(nx, ny));
            dir.push(make_pair(i, 0));
            Bfs();
        }
        
    }


    if(pq.empty() == true)
    {
        cout << 0;
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
    if(x >= 0 && x<=H-1 && y>=0 && y<= W-1) return true;
    else return false;
}
void Bfs()
{
    while(que.empty() != true)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        int direction = dir.front().first;
        int m_count = dir.front().second;
        dir.pop();

        for(int i = 0; i < 4; i++)
        {
           
            int t_m_count = m_count;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(direction != i) 
            {
                t_m_count += 1;
            }
            if(map[nx][ny] == 'C')
            {
                if(t_m_count <= visited[nx][ny])
                {
                    visited[nx][ny] = t_m_count;
                    pq.push(t_m_count);
                }
            }
            else if(Chk(nx, ny) && direction != db[i] && map[nx][ny] != '*' && visited[nx][ny] >= t_m_count)
            {
                visited[nx][ny] = t_m_count;
                que.push(make_pair(nx, ny));
                dir.push(make_pair(i, t_m_count));
            } 

        }
          
    }
}
