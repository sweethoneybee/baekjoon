#include <iostream>
#include <string>
using namespace std;

string& fun1(string &&a)
{
    cout << "address of a : " << &a << endl;
    return a;
}
int main(void)
{
    string tmp = fun1("wow");
    cout << tmp << endl;
    system("pause");
    return 0;
}