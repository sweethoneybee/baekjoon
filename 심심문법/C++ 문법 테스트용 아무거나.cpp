#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main(void)
{
    srand(time(NULL));
    int a;
    
    while(cin >> a)
    {
        cout << a << endl;
    }
    
    system("pause");
    return 0;
}