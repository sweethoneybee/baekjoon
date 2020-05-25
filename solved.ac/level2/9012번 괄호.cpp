#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> s;
stack<int> temp;

int T;
bool answer = true;
int main(void)
{
    cin >> T;
    string input;
    int first, second;
    for(int t = 0; t < T; t++)
    {
        answer = true;
        first = second = 0;
        while(s.empty() != true)
        {
            s.pop();
        }
        while(temp.empty() != true)
        {
            temp.pop();
        }
        cin >> input;

        for(int i = 0, size = input.length(); i < size; i++)
        {
            if(input[i] == '(')
            {
                first++;
                s.push(input[i]);
            }
            else if(input[i] == ')')
            {
                second++;
                answer = false;
                while(s.empty() != true)
                {
                    int par = s.top();
                    if(par == '(')
                    {
                        s.push(input[i]);
                        while(temp.empty() != true)
                        {
                            s.push(temp.top());
                            temp.pop();
                        }
                        answer = true;
                        break;
                    }
                    else if(par == ')')
                    {
                        temp.push(s.top());
                        s.pop();
                        if(s.empty()) break;
                        else
                        {
                            temp.push(s.top());
                            s.pop();
                        }
                        
                    }
                }

                if(answer == false) break;
            }
        }

        if(answer == true && first == second) cout << "YES\n";
        else cout << "NO\n";
    }
    system("pause");
    return 0;
}