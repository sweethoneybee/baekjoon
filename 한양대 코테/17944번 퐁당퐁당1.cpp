#include <iostream>
using namespace std;

int main(void)
{
    int N, T;
    cin >> N >> T;

    int answer = 0;
    int plus = 1;
    for(int i = 0; i < T; i++)
    {
        answer += plus;
        if(answer == 2 * N) plus = -1;
        else if(answer == 1) plus = 1;
    }

    cout << answer;
    system("pause");
    return 0;
}