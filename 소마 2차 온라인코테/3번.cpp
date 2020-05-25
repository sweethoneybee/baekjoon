#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Man
{
    int start;
    int end;
    int index;
    int canAtk;
}Man;
int main(void)
{
    int N;
    cin >> N;
    vector<Man> v;
    for(int i = 0; i < N; i++)
    {
        Man temp;
        cin >> temp.start;
        cin >> temp.end;
        temp.index = i;
        temp.canAtk = 0;
        v.push_back(temp);
    }
  
    sort(v.begin(), v.end(), [](const Man &a, const Man &b)->bool
    {
        return a.start < b.start;
    });
    priority_queue<int, vector<int>, greater<int>> pq;

    v[0].canAtk = 0;
    pq.push(v[0].end);
    for(int i = 1; i < N; i++)
    {
        if(v[i-1].start == v[i].start)
        {
            v[i].canAtk = v[i-1].canAtk;
        }
        else
        {
            while(pq.empty() != true && v[i].start >= pq.top())
            {
                pq.pop();
            }
            v[i].canAtk = pq.size();
            pq.push(v[i].end);
        }
    }

    sort(v.begin(), v.end(), [](const Man &a, const Man &b)->bool
    {
        return a.index < b.index;
    });

    for(int i = 0; i < N; i++)
    {
        cout << v[i].canAtk << endl;
    }
    system("pause");
    return 0;
}

// 4
// 12 71
// 51 79
// 17 87
// 9 28