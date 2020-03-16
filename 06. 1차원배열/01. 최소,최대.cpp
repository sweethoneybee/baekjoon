#include <iostream>
using namespace std;

int main(void)
{
    int N;
    int min = 1000001;
    int max = -1000001;

    int num;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        if(num > max)
        {
            max = num;
        }
        if(num < min)
        {
            min = num;
        }
    }

    cout << min << " " << max;
    system("pause");
    return 0;
}