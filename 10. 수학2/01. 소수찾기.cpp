#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int num[N] = {0};
    for(int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    int prime = 0;
    for(int n = 0; n < N; n++)
    {
        if(num[n] != 1)
        {
            bool isPrime = 1;
            for(int i = 2; i < num[n]; i++)
            {
                if(num[n] % i == 0)
                {
                    isPrime = 0;
                    break;
                }
            }

            if(isPrime == 1)    prime++;
        }
    }

    cout << prime;
    system("pause");
    return 0;
}