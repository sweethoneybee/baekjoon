#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < 10; i++)
    {
        pq.push(i);
    }

    for(int i = 0; i < 10; i++)
    {
        cout << pq.top() << "\n";
        pq.pop();

    }
    
    cout << endl;
    vector<int> a;
    for(int i = 0; i < 10; i++)
    {
        a.push_back(i);    
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < 10; i++)
    {
        cout << a[i] << "\n";
    }

    system("pause");
    return 0;
}