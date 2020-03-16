#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class animal
{
    public:
    int sheep;
    int wolf;
    bool run;
    animal(int x, int y, bool z) : sheep(x), wolf(y), run(z){}
};
queue<pair<int, int>> que;
vector<animal> count;
int R, C;
char field[250][250] = {0};
bool visited[250][250] = {0};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool Chk(int x, int y);
void Bfs(int);

int main(void)
{
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> field[i][j];
        }
    }

    int idx = 0;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if((field[i][j] == 'v' || field[i][j] == 'o' )&& visited[i][j] == 0)
            {
                visited[i][j] = 1;
                que.push(make_pair(i, j));
                
                count.push_back(animal(0, 0, 0));
                Bfs(idx++);
            }
        }
    }

    int countSize = count.size();
    int sheeps = 0;
    int wolves = 0;
    for(int i = 0; i < countSize; i++)
    {
        if(count[i].run == 0)
        {
            if(count[i].sheep > count[i].wolf)
            {
                sheeps += count[i].sheep;
            }
            else
            {
                wolves += count[i].wolf;
            }
            
        }
    }

    cout << sheeps << " " << wolves << endl;

    
    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x>=0 && x<= R-1 && y>=0 && y <=C-1) return true;
    else return false;
}
void Bfs(int index)
{
    while(que.empty() != true)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        if(field[x][y] == 'o') count[index].sheep++;
        if(field[x][y] == 'v') count[index].wolf++;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Å»Ãâ °í·Á½Ã
            // if(!Chk(nx, ny))
            // {
            //     count[index].run = 1;
            // }

            if(Chk(nx, ny) && visited[nx][ny] == 0 && field[nx][ny] != '#')
            {
                visited[nx][ny] = 1;
                que.push(make_pair(nx, ny));
            }
        }
    }
}