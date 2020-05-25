#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string input = "";
    bool chk = true;
    cin >> input;
    while(input != "0")
    {
        chk = true;
        
        auto i = input.begin();
        auto j = input.rbegin();
        for(auto end = input.end(); i != end; ++i, ++j)
        {
            if(*i != *j)
            {
                chk = false;
                break;
            }
        }

        if(chk == true)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
        cin >> input;
    }
    system("pause");
    return 0;
}