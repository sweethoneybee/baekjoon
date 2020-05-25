#include <iostream>
#include <queue>
using namespace std;
queue<int> que;

int T, n, teammate;
int arr[100001] = {0};
bool visited[100001] = {0};
void dfs(int index);

int main(void)
{
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        fill_n(arr, 100001, 0);
        fill_n(visited, 100001, 0);
        teammate = 0;
        
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i+1];
        }

        for(int i = 1; i <= n; i++)
        {
            if(visited[i] == 0)
            {
                que.push(i);
                visited[i] = 1;
                dfs(i);
            }
        }

        int answer = n - teammate;
        cout << answer << "\n";
    }
    system("pause");
    return 0;
}

void dfs(int index)
{
    int visit = arr[index];
    if(visited[visit] == 0)
    {
        que.push(visit);
        visited[visit] = 1;
        dfs(visit);
    }

    else
    {
        int chk = 0;
        while(que.empty() != true)
        {
            if(que.front() == visit)
            {
                teammate += que.size();
                break;
            }
            que.pop();
        }


        while(que.empty() != true)
        {
            que.pop();
        }
    }
}