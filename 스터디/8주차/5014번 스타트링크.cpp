#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
queue<int> que;

void Bfs(int *);
int main(void)
{
    cin >> F >> S >> G >> U >> D;

    int *arr = new int[F+1];
    fill_n(arr, F+1, 0);
    arr[0] = -1;
    
    if(G - S == 0)
    {
        cout << 0;
    }
    else
    {
        que.push(S);
        arr[S] = 1;
        Bfs(arr);

        if(arr[G] == 0)
        {
            cout << "use the stairs";
        }
        else
        {
            cout << arr[G] - 1;
        }
        
    
    }
    

    delete[] arr;
    system("pause");
    return 0;
}

void Bfs(int *arr)
{
    while(que.empty() != true)
    {
        int x = que.front();
        que.pop();

        if(x == G) break;
        if(x + U <= F && arr[x + U] == 0)
        {
            arr[x + U] = arr[x] + 1;
            que.push(x+U);
        }

        if(x - D >= 1 && arr[x - D] == 0)
        {
            arr[x - D] = arr[x] + 1;
            que.push(x - D);
        }

    }
}