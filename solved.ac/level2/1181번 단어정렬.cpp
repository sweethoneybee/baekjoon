#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void)
{
    set<string> s[50];
    int N = 0;
    cin >> N;
    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        s[input.length() - 1].insert(input);
    }
    for(int i = 0; i < 50; i++)
    {
        if(s[i].empty() != true)
        {
            for(auto &n : s[i])
            {
                cout << n << "\n";
            }
        }
    }
    system("pause");
    return 0;
}