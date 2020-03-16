#include <iostream>
using namespace std;

int main(void)
{
    int hour, min;
    int a_hour, a_min;
    const int Chang = 45;

    cin >> hour >> min;
    if(min - 45 < 0)
    {
        if(hour == 0)
        {
            a_hour = 23;
        }
        else
        {
            a_hour = --hour;
        }
        a_min = 60 + min - 45;
    }
    else
    {
        a_hour = hour;
        a_min = min - 45;
    }
    
    cout << a_hour << ' ' << a_min;
    system("pause");
    return 0;
}