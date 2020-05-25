#include <queue>
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    priority_queue<int, vector<int>, less<int>> pq;
    
    for(int i = 0; i < 5; i++)
    {
        int temp; cin >> temp;
        pq.push(temp);
    }
    for(int i = 0; i < 5; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    system("pause");
    return 0;
}