#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int root[600][1100] = {0};
int tile[600][1100] = {0};
int mark[300000] = {0};
int r[300000] = {0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool Chk(int, int);
void Bfs();
int makeRoot(vector<int> &answer);
int N;
int Index = 0;
pair<int, int> max_tile_cor;
queue<int> que;
vector<int> answer, v[300000];

int main(void)
{
    cin >> N;
    for(int i = 0 ; i < N; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < N; j++)
            {
                for(int k = 0; k < 2; k++)
                {
                    cin >> root[i][j * 2 + k];
                    tile[i][j * 2 + k] = Index;
                }
                Index++;
            }
        }

        else
        {
            for(int j = 1; j < N; j++)
            {
                for(int k = 1; k >= 0; k--)
                {
                    cin >> root[i][j * 2 - k];
                    tile[i][j * 2 - k] = Index;
                }
                Index++;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N * 2; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(Chk(nx, ny) && tile[nx][ny] != tile[i][j] && root[nx][ny] == root[i][j])
                {
                    v[tile[i][j]].push_back(tile[nx][ny]);
                }
            }
        }
    }


    
    fill_n(mark, 300000, -1);

    mark[0] = 0;
    r[0] = -1;

    for(que.push(0); !que.empty(); que.pop())
    {
        int c = que.front();
        for(int i = 0; i < v[c].size(); ++i)
        {
            int o = v[c][i];
            if(mark[o] == -1)
            {
                mark[o] = mark[c] + 1;
                r[o] = c;
                que.push(o);
            }
        }
    }

    int f;
    for(f = N * N - N / 2 - 1; mark[f] == -1; f--);

    for(int x = f; x != -1; x = r[x])
        answer.push_back(x);
    

    
    cout << answer.size() << endl;
    for(int i = answer.size() - 1; i >= 0; i--)
    {
        cout << answer[i]+1 << " ";
    }
    
    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x >= 0 && x <= N - 1 && y>=0 && y <= N * 2 - 1) return true;
    else return false;
}
