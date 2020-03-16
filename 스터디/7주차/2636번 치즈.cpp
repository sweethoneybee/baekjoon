#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cheese[100][100] = {0};
bool visited[100][100] = {0};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int N, M;
int cheeseCnt = 0;
int meltCnt = 0;
int answer = 0;
int time = 0;
vector<queue<pair<int, int>>> melt;
queue<pair<int, int>> que;
bool Chk(int , int);
void BfsMelt();

int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> cheese[i][j];
            if(cheese[i][j] == 1) 
            {
                cheeseCnt++;
            }
        }
    }

    while(cheeseCnt != 0)
    {
        meltCnt = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(cheese[i][j] == 0 && visited[i][j] == 0)
                {
                    visited[i][j] = 1;
                    que.push(make_pair(i, j));
                    BfsMelt();
                }
            }
        }

        if((cheeseCnt - meltCnt) > 0 )
        {
            fill_n(visited[0], sizeof(visited), 0);
            time++;
            //cout << "time : " << time << ", cheeseCnt : " << cheeseCnt << ", meltCnt : " << meltCnt << endl;
            cheeseCnt -= meltCnt;
            int size = melt.size();
            for(int i = 0; i<size; i++)
            {
                while(melt[i].empty() != true)
                {
                    int x = melt[i].front().first;
                    int y = melt[i].front().second;
                    melt[i].pop();

                    cheese[x][y] = 0;
                }
            }
        }
        else
        {
            answer = cheeseCnt;
            break;
        }
    }

    cout << time + 1 << endl;
    cout << answer;
    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x >= 0 && x<= N-1 && y>=0 && y<=M-1) return true;
    else return false;
}
void BfsMelt()
{
    bool pot = 1;
    queue<pair<int, int>> tempQue;
    while(que.empty() != true)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!Chk(nx, ny)) pot = 0;
            if(Chk(nx, ny) && visited[nx][ny] == 0)
            {   
                if(cheese[nx][ny] == 0)
                {
                    visited[nx][ny] = 1;
                    que.push(make_pair(nx, ny));
                }
                else if(cheese[nx][ny] == 1)
                {
                    visited[nx][ny] = 1;
                    tempQue.push(make_pair(nx, ny));
                }
                
            }
        }
    }

    if(pot == 0)
    {
        meltCnt += tempQue.size();
        melt.push_back(tempQue);
    }
    else if(pot == 1)
    {
        while(tempQue.empty() != true)
        {
            tempQue.pop();
        }
    }
}
