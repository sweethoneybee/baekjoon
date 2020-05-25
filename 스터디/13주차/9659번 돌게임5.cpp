#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string a;
    cin >> a;

    int t = (a.back() - '0');
    if(t % 2 == 0) cout << "CY";
    else cout << "SK"; 
    system("pause");
    return 0;
}