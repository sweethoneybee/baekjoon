#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<pair<int, int>> que;
queue<int> answer;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int picture[100][100] = {0};
int d_picture[100][100] = {0};
int N;

void Bfs(int color, int picture[][100]);
bool Chk(int x, int y);

int main(void)
{
    cin >> N;
    
    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        for(int j = 0; j < N; j++)
        {
            picture[i][j] = input[j];
            d_picture[i][j] = input[j];
            if(d_picture[i][j] == 'G')
            {
                d_picture[i][j] = 'R';
            }
        }
    }

    int color = 0;
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(picture[i][j] != 0)
            {
                color = picture[i][j];
                que.push(make_pair(i, j));
                picture[i][j] = 0;
                count++;
                Bfs(color, picture);
            }
        }
    }
    answer.push(count);

    color = 0;
    count = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(d_picture[i][j] != 0)
            {
                color = d_picture[i][j];
                que.push(make_pair(i, j));
                d_picture[i][j] = 0;
                count++;
                Bfs(color, d_picture);
            }
        }
    }
    answer.push(count);
    
    cout << answer.front() << " ";
    answer.pop();
    cout << answer.front();

    system("pause");
    return 0;
}

void Bfs(int color, int picture[][100])
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

            if(Chk(nx, ny) && picture[nx][ny] == color)
            {
                que.push(make_pair(nx, ny));
                picture[nx][ny] = 0;
            }
        }
    }
}
bool Chk(int x, int y)
{
    if(x >= 0 && x < N && y >= 0 && y < N)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}