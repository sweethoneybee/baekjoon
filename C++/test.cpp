#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct sub
{
    int score;
    int time;
};
int main(void)
{
    int N;
    cin >> N;
    int answer = 0;

    stack<int> next;
    next.push(0);
    bool chk = 0;
    vector<sub> me;
    sub widget;
    widget.score = 0;
    widget.time = 1111111;
    me.push_back(widget);
    int index = next.top();
    int where = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> chk;
        if(chk == 1)
        {
            int a, b;
            cin >> a >> b;
            sub temp;
            temp.score = a; temp.time = b;

            me.push_back(temp);
            where += 1;
            index = where;
            next.push(index);

            me[index].time -= 1;
            if(me[index].time == 0)
            {
                answer += me[index].score;
                next.pop();
                index = next.top();
            }
        }
        else 
        {
            me[index].time -= 1;
            if(me[index].time == 0)
            {
                answer += me[index].score;
                next.pop();
                index = next.top();
            }
        }
    }

    cout << answer;
    system("pause");
    return 0;
}