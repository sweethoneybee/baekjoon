#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    long long *box = new long long[N];
    for(int i = 0; i < N; i++)
    {
        cin >> box[i];
    }
    cout << "wow";
    long long *findMax = new long long[N];
    findMax[0] = box[0];

    for(int i = 1; i < N; i++)
    {
        long long me, both;
        me = box[i];
        both = box[i] + findMax[i-1];

        if(me > both)
        {
            findMax[i] = me;
        }
        else
        {
            findMax[i] = both;
        }
    }
    sort(findMax, findMax + N, [](long long &a, long long &b)->bool{
        return a > b;
    });

    cout << findMax[0];
    system("pause");
    return 0;
}