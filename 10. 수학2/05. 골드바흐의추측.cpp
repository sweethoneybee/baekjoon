#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(void)
{
    int T;
    cin >> T;

    const int NUMBER = 10000;
    int prime[NUMBER+1];
    for(int i = 1; i <= NUMBER; i++)
    {
        prime[i] = i;
    }

    prime[1] = 0;
    for(int i = 2; i <= sqrt(double(NUMBER)); i++)
    {
        if(prime[i] != 0)
        {
            int multiple = i;
            for(int j = 2; multiple * j <= NUMBER ; j++)
            {
                prime[multiple * j] = 0;
            }
        }
    }
    
    vector<int> GOLD;
    for(int i = 1; i <= NUMBER;i++)
    {
        if(prime[i] != 0)
            GOLD.push_back(prime[i]);
    }


    for(int t = 0; t<T; t++)
    {
        int n;
        cin >> n;

        int a, b;
        a = -1, b = 10001;

        int i = 0;
        while(n - GOLD[i] >= n/2)
        {
            if(prime[n-GOLD[i]] !=0 )
            {
                a = GOLD[i];
                b = n-GOLD[i];
            }

            i++;
        }

        cout << a << " " << b << "\n";
    }

    system("pause");
    return 0;
}