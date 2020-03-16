#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
// #include <functional>
using namespace std;
void findApart(queue<int*> &que, int &count, int N, priority_queue< int, vector<int>, greater<int> > &pQue);
void findDangi(int *center, int &count, int N);

int main(void)
{
    int N = 0;
    cin >> N;
    int apart[N+2][N+2] = {0};
    string input;

    for(int i = 1; i <= N; i++)
    {
        cin >> input;
        for(int j = 1; j <= N; j++)
        {
            apart[i][j] = input[j-1] - '0';
        }
    }
    for(int i = 0; i <= N+1; i++)
    {
        apart[0][i] = -2;
        apart[i][0] = -2;
        apart[N+1][i] = -2;
        apart[i][N+1] = -2;
    }  

    queue<int*> que;
    int count = 0;
    priority_queue<int, vector<int>, greater<int> > answer;
    
    que.push(&apart[1][1]);
    if(apart[1][1] == 1)
    {
        findDangi(&(apart[1][1]), count, N);
        answer.push(count);
    }
    findApart(que, count, N, answer);

    cout << answer.size() << "\n";
    while(answer.empty() != true)
    {
        cout << answer.top() << "\n";
        answer.pop();
    }
    system("pause");
    return 0;
}

void findApart(queue<int*> &que, int &count, int N, priority_queue< int, vector<int>, greater<int> > &pQue)
{
    while(que.empty() != true)
    {
        int *center = que.front();
        que.pop();
        center[0] = -1;
        count = 0;

        // 나보다 밑
        if(center[N+2] == 0) 
        {
            que.push(&(center[N+2]));
            center[N+2] = -1;    
        }
        else if(center[N+2] == 1)
        {
            findDangi(&(center[N+2]), count, N);
            pQue.push(count);
            count = 0;
        }

        // 나보다 오른쪽
        if(center[1] == 0) 
        {
            que.push(&(center[1]));  
            center[1] = -1;  
        }
        else if(center[1] == 1)
        {
            findDangi(&(center[1]), count, N);
            pQue.push(count);
            count = 0;
        }

        // 나보다 위
        if(center[-(N+2)] == 0) 
        {
            que.push(&(center[-(N+2)]));    
            center[-(N+2)] = -1;
        }
        else if(center[-(N+2)] == 1)
        {
            findDangi(&(center[-(N+2)]), count, N);
            pQue.push(count);
            count = 0;
        }

        // 나보다 왼쪽
        if(center[-1] == 0) 
        {
            que.push(&(center[-1])); 
            center[-1] = -1;   
        }
        else if(center[-1] == 1)
        {
            findDangi(&(center[-1]), count, N);
            pQue.push(count);
            count = 0;
        }

    }
}

void findDangi(int *center, int &count, int N)
{
    count++;
    center[0] = 0; // findApart에서 안 본 걸로 침
    
    // 나보다 아래
    if(center[N+2] == 1)
    {
        findDangi(&(center[N+2]), count, N);
    }
    
    // 나보다 오른쪽
    if(center[1] == 1)
    {
        findDangi(&(center[1]), count, N);
    }

    // 나보다 위
    if(center[-(N+2)] == 1)
    {
        findDangi(&(center[-(N+2)]), count, N);
    }

    // 나보다 왼쪽
    if(center[-1] == 1)
    {
        findDangi(&(center[-1]), count, N);
    }

}
