#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(void)
{
    map<int, vector<string>> m;
    int N = 0;
    cin >> N;

    int age;
    string name;
    for(int i = 0; i < N; ++i)
    {
        cin >> age;
        cin >> name;
        
        m[age].push_back(name);
    }

    for(auto &n : m)
    {
        for(auto &i : n.second)
        {
            cout << n.first << " " << i << "\n";
        }
    }
    system("pause");
    return 0;
}
