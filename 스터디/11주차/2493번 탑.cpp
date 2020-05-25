#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<pair<int, int>> stk;
int N;
int main(void)
{
    cin >> N;

    vector<int> input(N, 0);
    vector<int> answer(N, 0);
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        input[i] = a;
    }

    stk.push(make_pair(input[N-1], N-1));
    for(int i = input.size() - 2; i >= 0; --i)
    {
        if(stk.top().first > input[i])
        {
            stk.push(make_pair(input[i], i));
        }
        else
        {
            while(stk.empty() != true && stk.top().first < input[i])
            {
                answer[stk.top().second] = i + 1;
                stk.pop();
            }
            stk.push(make_pair(input[i], i));
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << answer[i] << " ";
    }
    system("pause");
    return 0;
}