#include <iostream>
using namespace std;

int main(void)
{
    char temp[10];
    for(int i = 0; i < 10; i++) cin >> temp[i];

    for(int i = 0; i < 10; i++) cout << temp[i] << " ";
    cout << "\n";

    //int로 캐스팅
    for(int i = 0; i < 10; i++) cout << int(temp[i]) << " ";
    cout << "\n";

    system("pause");
    return 0;
}