#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
    int N, M;
    vector<int> prime;
    
    cin >> M >> N;

    for(int n = M; n <= N; n++)
    {
        if(n != 1)
        {
            bool isPrime = 1;
            for(int i = 2; i < n; i++)
            {
                if(n % i == 0)
                {
                    isPrime = 0;
                    break;
                }
            }

            if(isPrime == 1)
            {
                prime.push_back(n);
            }
        }
    }

    if(prime.size() == 0)   cout << -1;
    else
    {
        int minimum = prime[0];
        int sum = 0;

        for(auto i = prime.begin(); i < prime.end();i++)
        {
            sum += *i;
        }

        cout << sum << endl;
        cout << minimum;
    }
    
    system("pause");
    return 0;
}