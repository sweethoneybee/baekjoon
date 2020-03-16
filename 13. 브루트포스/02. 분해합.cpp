#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int answer = 0;
    int digit = 1;
    int n = N;
    while(n >= 10)
    {
        n /= 10;
        digit += 1;
    }

    int sum; 
    int i = 1;
    for(int j =0; j < digit-2; j++)
        i *= 10;
 
    for(; i <= N-1; i++)
    {
        sum = i;
        int k = i;
        while(k > 0)
        {
            sum += k % 10;
            k /= 10;
        }

        if(sum == N)
        {
            answer = i;
            cout << answer;
            break;
        }
    }

    if(answer == 0)
        cout << answer;

    cin >> N;
    return 0;
}