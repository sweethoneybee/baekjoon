#include <iostream>
#include <queue>
using namespace std;

//변수 선언
int w, h , T;
int building[1000][1000] = {0};
int queCount = 0; 
int fireMax = 0; 
int sangeunCount = 0;
int moveMax = 0;
pair<int, int> start;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
//큐선언
queue<pair<int, int>> que;
priority_queue<int, vector<int>, greater<int>> pq;

//함수 선언
void Bfs();
bool Chk(int , int);

int main(void)
{
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cin >> w >> h;
        for(int i = 0; i < h; i++)
        {
            string input;
            cin >> input;
            for(int j = 0; j < w; j++)
            {
                building[i][j] = input[j];
                
                if(building[i][j] == '*')
                {
                    fireMax++;
                    que.push(make_pair(i, j));
                }

                if(building[i][j] == '@')
                {
                    moveMax++;
                    building[i][j] = 0;
                    start = make_pair(i, j);
                }

                if(building[i][j] == '.')
                {
                    building[i][j] = -1;
                }
            }
        }
        // Bfs
        que.push(start);
        Bfs();

        // 출력
        int answer = 0;
        if(pq.empty() != true) answer = pq.top();
        if(answer != 0) cout << answer << "\n";
        else cout << "IMPOSSIBLE\n";

        // 초기화
        fill_n(building[0], 1000*1000, 0);
        queCount = 0; fireMax = 0;
        sangeunCount = 0; moveMax = 0;

        int temp = 0; temp = pq.size();
        for(int i = 0; i < temp; i++)
        {
            pq.pop();
        }    
    }
    system("pause");
    return 0;
}

void Bfs()
{
    int newFireMax = 0;
    int newMoveMax = 0;
    while(que.empty() != true)
    {
        if(queCount < fireMax)
        {
            queCount++;
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(Chk(nx, ny) && building[nx][ny] == -1)
                {
                    building[nx][ny] = '*';
                    que.push(make_pair(nx, ny));
                    newFireMax++;
                }
            }

        }
        else
        {
            for(int k = 0; k < moveMax; k++)
            {
                int x = que.front().first;
                int y = que.front().second;
                que.pop();

                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(Chk(nx, ny) && building[nx][ny] == -1)
                    {
                        building[nx][ny] = 1 + building[x][y];
                        que.push(make_pair(nx, ny));
                        newMoveMax++;
                    }
                    else if(!Chk(nx, ny)) 
                    {
                        pq.push(building[x][y] + 1);
                    }
                }
            }

            // 갱신
            queCount = 0; fireMax = newFireMax; newFireMax = 0;
            moveMax = newMoveMax; newMoveMax = 0;
        }
        
    }
}

bool Chk(int x, int y) 
{
    if(x >= 0 && x <= h-1 && y >= 0 && y <= w-1) return true;
    else return false;
}