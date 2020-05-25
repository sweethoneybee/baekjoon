#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    queue<int> que;
    for(int i = 1; i <= N; i++)
    {
        que.push(i);
    }
    
    while(que.size() != 1)
    {
        que.pop();
        if(que.size() == 1)
            break;
        
        que.push(que.front());
        que.pop();
    }

    cout << que.front();
    system("pause");
    return 0;
}