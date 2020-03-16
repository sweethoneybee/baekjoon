#include <iostream>
using namespace std;

int main(void)
{
    int sum = 0;
    for(int i = 0; i < 5; i++)
    {
        int a = 0;
        cin >> a;
        if(a < 40)
        {
            a = 40;
        }

        sum += a;
    }

    cout << sum / 5;
    system("pause");
    return 0;
}