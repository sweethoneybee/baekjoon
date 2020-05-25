#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    // int N;
    // vector<string> vec;
    // cin >> N;
    // cout << N << "times input\n";
    // cin.get();
    // for(int i = 0; i < N; i++)
    // {
    //     string tmp;
    //     getline(cin, tmp);
    //     vec.push_back(tmp);
    //     for(auto &n : vec)
    //     {
    //         cout << n << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "sort by abc\n";
    // sort(vec.begin(), vec.end());
    // cout << "sort by length\n";
    // sort(vec.begin(), vec.end(), [](string &a, string &b)->bool
    // {
    //     return a.length() < b.length();
    // });
    // vec.erase(remove(vec.begin(), vec.end(), "abc"), vec.end());
    // for(auto &n : vec)
    // {
    //     cout << n << " ";
    // }
    // cout << endl;

    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(3);

    vector<int> answer;
    auto current = v.begin();
    while(true)
    {
        current = find_if(current, v.end(), [](int &i)->bool{ return i % 3 == 0; });
        if(current == v.end()) break;
        answer.push_back(*current);
        ++current;
    }
    for( auto &n : answer)
    {
        cout << n << " ";
    }
    system("pause");
    return 0;
}