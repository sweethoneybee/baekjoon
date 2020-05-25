#include <iostream>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    int answer = 1;
    for(int i = 0; i < K; i++)
    {
        answer *= (N - i);
    }
    for(int i = 0; i < K; i++)
    {
        answer /= (K - i);
    }
    
    cout << answer;
    system("pause");
    return 0;
}