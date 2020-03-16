#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int N;
bool input[100][100] = {0};
bool visited[100] = {0};
queue<int> que;
void Bfs();
bool a[100][100] {0};
int main(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            cin >> input[i][j];       
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(input[i][j] == 1)
            {
                que.push(j);
                Bfs();
            }
        }
        for(int j = 0; j < N; j++)
        {
            if(visited[j] == 1)
            {
                a[i][j] = 1;
            }
        }

        fill_n(visited, sizeof(visited), 0);
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}


void Bfs()
{
    while(que.empty() != true)
    {
        int index = que.front();
        que.pop();
        
        visited[index] = 1;
        for(int i = 0; i < N; i++)
        {
            if(input[index][i] == 1 && visited[i] == 0)
            {
                que.push(i);
            }
        }
    }

 
}