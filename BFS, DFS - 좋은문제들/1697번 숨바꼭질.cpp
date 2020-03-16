#include <iostream>
#include <queue>
using namespace std;

int N, K;
int position[100001] = {0};
queue<int> que;

void Bfs();
bool Chk(int x);
int main(void)
{
    cin >> N >> K;

    position[N] = 1;
    int N1 = N + 1;
    int N2 = N - 1;
    int N3 = N * 2;

    if(Chk(N1))
    {
        position[N1] = position[N]+1;
        que.push(N1);
    }

    if(Chk(N2))
    {
        position[N2] = position[N]+1;
        que.push(N2);
    }

    if(Chk(N3))
    {
        position[N3] = position[N]+1;
        que.push(N3);
    }
    
    if(N==K)
    {
        cout << "0";
    }
    else
    {
        Bfs();
        cout << position[K] - 1;
    }
    
    system("pause");
    return 0;
}

void Bfs()
{
    while(que.empty() != true)
    {
        int x = que.front();
        que.pop();

        int x1 = x + 1;
        int x2 = x - 1;
        int x3 = x * 2;

        if(Chk(x1) && position[x1] == 0)
        {
            position[x1] = position[x] + 1;
            que.push(x1);
        }
        if(Chk(x2) && position[x2] == 0)
        {
            position[x2] = position[x] + 1;
            que.push(x2);
        }
        if(Chk(x3) && position[x3] == 0)
        {
            position[x3] = position[x] + 1;
            que.push(x3);
        }
    
        if( x1 == K || x2 == K || x3 == K)
        {
            return;
        }
    }
}

bool Chk(int x)
{
    if(x >= 0 && x < 100001)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}