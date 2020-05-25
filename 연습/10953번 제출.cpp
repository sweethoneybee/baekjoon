#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int T;
    string temp;
    cin >> T;
    for(int i = 0 ; i < T; i++)
    {
        cin >> temp;
        cout << (temp[0] - '0') + (temp[2] - '0') << endl;    
    }
    system("pause");

    return 0;
}