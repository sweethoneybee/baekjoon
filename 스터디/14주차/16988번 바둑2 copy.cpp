#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct canKill
{
    int kill;
    vector<pair<int, int>> coor;
} canKill;

queue<pair<int, int>> que;
queue<pair<int, int>> howNeed;
vector<canKill> two;
priority_queue<int, vector<int>, less<int>> pq;
int N, M;
int answer = 0;
int combAnswer = 0;
int pan[20][20] = {0};
bool visited[20][20] = {0};
int oneKill[20][20] = {0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool chk(int x, int y);
void bfs();
void findMaxKill();
int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> pan[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(pan[i][j] == 2 && visited[i][j] == 0)
            {
                visited[i][j] = 1;
                que.push(make_pair(i, j));
                bfs();
            }
        }
    }

    findMaxKill();

    cout << answer;
    system("pause");
    return 0;
}
bool chk(int x, int y)
{
    if(x >= 0 && x <= N-1 && y >= 0 && y <= M-1) return true;
    else return false;
}
void bfs()
{
    int size = 1;
    while(que.empty() != true)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!chk(nx, ny)) continue;

            if(pan[nx][ny] == 0 && visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                howNeed.push(make_pair(nx, ny));
            }
            else if(pan[nx][ny] == 2 && visited[nx][ny] == 0)
            {
                size++;
                visited[nx][ny] = 1;
                que.push(make_pair(nx, ny));
            }
        }
    }
    if(howNeed.size() == 1)
    {
        visited[howNeed.front().first][howNeed.front().second] = 0;
        oneKill[howNeed.front().first][howNeed.front().second] += size;
        howNeed.pop();
    }
    else if(howNeed.size() == 2)
    {
        canKill temp;
        temp.kill = size;
        temp.coor.push_back(make_pair(howNeed.front().first, howNeed.front().second));
        visited[howNeed.front().first][howNeed.front().second] = 0;
        howNeed.pop();
        temp.coor.push_back(make_pair(howNeed.front().first, howNeed.front().second));
        visited[howNeed.front().first][howNeed.front().second] = 0;
        howNeed.pop();
        two.push_back(temp);
    }
    else
    {
        while(howNeed.empty() != true)
        {
            visited[howNeed.front().first][howNeed.front().second] = 0;
            howNeed.pop();
        }
    }
}
void findMaxKill()
{
    int maxAnswer = 0;

    // First find max kill number with two stones ( plus kill number, killed by same coord with one stone).
    // Compare that with max kill number with one stones.
    for(const auto &n : two)
    {
        int tempAnswer = n.kill;
        int x1 = n.coor[0].first; int y1 = n.coor[0].second;
        int x2 = n.coor[1].first; int y2 = n.coor[1].second;
        tempAnswer += oneKill[x1][y1];
        tempAnswer += oneKill[x2][y2];

        for(const auto& m : two)
        {
            if(&n != &m)
            {
                if(x1 == m.coor[0].first && y1 == m.coor[0].second
                && x2 == m.coor[1].first && y2 == m.coor[1].second)
                {
                    tempAnswer += m.kill;
                }
                if(x2 == m.coor[0].first && y2 == m.coor[0].second
                && x1 == m.coor[1].first && y1 == m.coor[1].second)
                {
                    tempAnswer += m.kill;
                }
            }
        }

        if(tempAnswer > maxAnswer)
        {
            maxAnswer = tempAnswer;
        }
    }

    int oneTempAnswer = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(oneKill[i][j] > 0)
            {
                pq.push(oneKill[i][j]);
            }
        }
    }
    for(int i = 0, size = pq.size(); i < size && i < 2; i++)
    {
        oneTempAnswer += pq.top();
        pq.pop();
    }

    if(maxAnswer > oneTempAnswer)
    {
        answer = maxAnswer;
    }
    else
    {
        answer = oneTempAnswer;
    }
}