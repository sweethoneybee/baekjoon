#include <iostream>
#include <queue>
using namespace std;

const int noFound = -1;
int N, M, T;
int castle[100][100] = {0};
int gramAnswer = 0;
int noGramAnswer = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

pair<int, int> gram;
queue<pair<int, int>> que;

void Bfs();
bool Chk(int x, int y);

int main(void)
{
    // 공주 위치
    cin >> N >> M >> T;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> castle[i][j];
            if(castle[i][j] == 1)
            {
                castle[i][j] = -1;
            }
            else if(castle[i][j] == 2)
            {
                castle[i][j] = 0;
                gram = make_pair(i, j);
            }
        }
    }

    
    castle[0][0] = 1; // visited;
    que.push(make_pair(0, 0));
    Bfs();

    noGramAnswer = castle[N-1][M-1] - 1;

    int gramX = gram.first;
    int gramY = gram.second;
    if(castle[gramX][gramY] != 0)
    {
        int x = (N-1) - gramX;
        int y = (M-1) - gramY;
        gramAnswer = castle[gramX][gramY] + x + y - 1;
    }

    
    int answer = 0;
    if(gramAnswer > 0 && noGramAnswer > 0)
    {
        if(gramAnswer > noGramAnswer) answer = noGramAnswer;
        else answer = gramAnswer;
    }
    else if(gramAnswer < 0 && noGramAnswer > 0)
    {
        answer = noGramAnswer;
    }
    else if(gramAnswer > 0 && noGramAnswer < 0)
    {
        answer = gramAnswer;
    }
    if(answer != 0 && answer <= T)
    {
        cout << answer;
    }
    else
    {
        cout << "Fail";
    }
    
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

            if(Chk(nx, ny) && castle[nx][ny] == 0)
            {
                castle[nx][ny] = castle[x][y] + 1;
                que.push(make_pair(nx, ny));
            }
        }
    }
}

bool Chk(int x, int y)
{
    if(x >= 0 && x<=N-1 && y>=0 && y<=M-1) return true;
    else return false;
}