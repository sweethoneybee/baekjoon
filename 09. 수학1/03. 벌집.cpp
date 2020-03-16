#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int start = 1;
    int result = 0;
    for(int n = 1;;n++)
    {
        start += 6 * (n-1);
        if(start >= N)
        {
            result = n;
            break;
        }
    }

    cout << result;
    system("pause");
    return 0;
}