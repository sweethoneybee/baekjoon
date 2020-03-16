#include <iostream>
using namespace std;

int main(void)
{
    int X;
    cin >> X;

    int fraction = 0;
    
    int n = 1;
    for(;;n++)
    {
        fraction += n;
        if(fraction >= X)
        {
            break;
        }
    }

    int boonmo, boonja;
    int count = fraction;
    if(n % 2 != 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(count == X)
            {
                boonja = 1 + i;
                boonmo = n - i;
            }
            count--;
        }
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(count == X)
            {
                boonja = n - i;
                boonmo = 1 + i;
            }
            count--;
        }
    }
    
    cout << boonja << "/" << boonmo;
    system("pause");
    return 0;
}