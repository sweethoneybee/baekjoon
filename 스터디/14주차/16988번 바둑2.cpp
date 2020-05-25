#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct canKill
{
    int need;
    int kill;
    vector<pair<int, int>> coor;
} canKill;

queue<pair<int, int>> que;
queue<pair<int, int>> howNeed;
vector<canKill> two;
vector<canKill> one;
int N, M;
int answer = 0;
int pan[20][20] = {0};
bool visited[20][20] ={0};
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
        canKill temp;
        temp.need = 1;
        temp.kill = size;
        temp.coor.push_back(make_pair(howNeed.front().first, howNeed.front().second));
        visited[howNeed.front().first][howNeed.front().second] = 0;
        howNeed.pop();
        one.push_back(temp);
    }
    else if(howNeed.size() == 2)
    {
        canKill temp;
        temp.need = 2;
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

    for(const auto &n : two)
    {
        int tempAnswer = n.kill;
        int x1 = n.coor[0].first; int y1 = n.coor[0].second;
        int x2 = n.coor[1].first; int y2 = n.coor[1].second;
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
        for(const auto &m : one)
        {
            if(m.coor[0].first == x1 && m.coor[0].second == y1)
            {
                tempAnswer += m.kill;
            }
            else if(m.coor[0].first == x2 && m.coor[0].second == y2)
            {
                tempAnswer += m.kill;
            }
        }

        if(tempAnswer > maxAnswer)
        {
            maxAnswer = tempAnswer;
        }
    }

    int maxTempAnswer = 0;
    pair<int, int> maxCoor;
    for(const auto &n : one)
    {
        int tempAnswer = n.kill;
        int x = n.coor[0].first; int y = n.coor[0].second;
        
        for(const auto &m : one)
        {   
            if(&n != &m)
            {
                if(x == m.coor[0].first && y == m.coor[0].second)
                {
                    tempAnswer += m.kill;
                }
            }
        }
        if(tempAnswer > maxTempAnswer)
        {
            maxCoor.first = n.coor[0].first;
            maxCoor.second = n.coor[0].second;
            maxTempAnswer = tempAnswer;
        }
    }
    int maxTempAnswer2 = 0;
    for(const auto &n : one)
    {
        int tempAnswer = n.kill;
        int x = n.coor[0].first; int y = n.coor[0].second;
        
        for(const auto &m : one)
        {   
            if(&n != &m)
            {
                if(x == m.coor[0].first && y == m.coor[0].second)
                {
                    tempAnswer += m.kill;
                }
            }
        }
        if(tempAnswer > maxTempAnswer2 && n.coor[0].first != maxCoor.first || n.coor[0].second != maxCoor.second)
        {
            maxTempAnswer2 = tempAnswer;
        }
    }

    maxTempAnswer += maxTempAnswer2;
    if(maxAnswer < maxTempAnswer)
    {
        maxAnswer = maxTempAnswer;
    }
    answer = maxAnswer;
}