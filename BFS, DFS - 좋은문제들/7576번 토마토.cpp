#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int M, N;

queue<pair<int, int>> que;
queue<int> days;

int Bfs(int **box);
bool Chk(int x, int y);

int main(void)
{
    cin >> M >> N;

    int** box = new int*[N+1];
    for(int i = 0; i <= N; i++)
    {
        box[i] = new int[M+1];
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> box[i][j];
        }
    }

    int answer = 0;
    int dayCount = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(box[i][j] == 1)
            {
                dayCount++;
                box[i][j] = 2;
                que.push(make_pair(i, j));
            }
        }
    }

    if(dayCount != 0)
    {
        days.push(dayCount);
        answer = Bfs(box);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(box[i][j] == 0)
            {
                answer = -1;
            }
        }
    }

    cout << answer;

    for(int i = 0; i <= N; i++)
    {
        delete[] box[i];
    }
    delete[] box;
    
    system("pause");
    return 0;
}

int Bfs(int **box)
{
    int answer = -1;
    int dayCount = 0;
    int roopCount = 0;
    int day = days.front();
    days.pop();

    while(que.empty() != true)
    {
        roopCount++;

        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(Chk(nx, ny) && box[nx][ny] == 0)
            {
                box[nx][ny] = 2;
                dayCount++;
                que.push(make_pair(nx, ny));
            }
        }

        if(roopCount == day)
        {
            roopCount = 0;
            days.push(dayCount);
            dayCount = 0;
            day = days.front();
            days.pop();
            answer++;
        }
    }
    return answer;
}
bool Chk(int x, int y)
{
    if(x >= 1 && x <= N && y >= 1 && y <= M)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}