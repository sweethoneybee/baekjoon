#include <iostream>
#include <string>
#include <vector>
using namespace std;

string L = "";
string R = "";

int main(void)
{
    vector<string> temp;
    temp.push_back("wow");
    temp.push_back("amazing");

    string a = "abcd";
    string b = "";
    for(int i = 0; i < 4; i++)
    {
        b = a.substr(i, 1) + b;
    }

    cout << "b : " << b.substr(1)<<endl;
    system("pause");
    return 0;
}