#include <iostream>
using namespace std;

int main(void)
{
    int N[10];
    for(int i =0; i<10; i++)
    {
        cin >> N[i];
    }

    int count[42] = {0};
    int result = 0;
    for(int i =0; i<10; i++)
    {
        count[N[i] % 42]++;
    }

    for(int i =0; i < 42; i++)
    {
        if(count[i] > 0) result++;
    }

    cout << result;
    system("pause");
    return 0;
}