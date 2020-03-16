#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int M, N, K, X, Y;
int bat[50][50] = {0};

bool Chk(int x, int y);
int Testing();
void FindBatchu(queue<pair<int, int>> &que, int (*bat)[50]);
void PrintAnswer(int *answer, int T);

int main(void)
{   
    int T;
    cin >> T;
    int answer[T];
    for(int t = 0; t < T; t++)
    {
        answer[t] = Testing();
    }

    PrintAnswer(answer, T);
    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x < 0 || x >= N || y < 0 || y >= M)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

int Testing()
{
    queue<pair<int, int>> que;
    int answer = 0;
    cin >> M >> N >> K;
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            bat[i][j] = 0;
        }
    }
    for(int k = 0; k < K; k++)
    {
        int X, Y;
        cin >> X >> Y;
        bat[Y][X] = 1;
    }


    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(bat[i][j] == 1)
            {
                que.push(make_pair(i, j));
                bat[i][j] = 0;
                FindBatchu(que, bat);
                answer++;
            }
        }
    }
    

    return answer;
}

void FindBatchu(queue<pair<int, int>> &que, int (*bat)[50])
{
    while(que.empty() != true)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx =  x + dx[i];
            int ny =  y + dy[i];
            if(Chk(nx, ny) && bat[nx][ny] == 1)
            {
                que.push(make_pair(nx,ny));
                bat[nx][ny] = 0;
            }
            // int nx = dx[i];
            // int ny = dy[i];
            // if(Chk(x+nx, y+ny) && bat[x+nx][y+ny] == 1)
            // {
            //     que.push(make_pair(x+nx,y+ny));
            //     bat[x+nx][y+ny] = 0;
            // }
        }
    }
}

void PrintAnswer(int *answer, int T)
{
    for(int i = 0; i < T; i++)
    {
        cout << answer[i] << "\n";
    }
}