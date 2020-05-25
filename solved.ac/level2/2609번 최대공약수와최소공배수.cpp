#include <iostream>
using namespace std;

int main(void)
{
    int A, B;
    cin >> A >> B;

    int small = 0;
    int big = 0;

    for(int i = 1; i <= B; ++i)
    {
        if((A * i) % B == 0)
        {
            small = A * i;
            break;
        }
    }

    int smallOne = 0;
    if(A > B) smallOne = B;
    else smallOne = A;
    for(int i = smallOne; i >= 1; --i)
    {
        if(A % i == 0 && B % i == 0)
        {
            big = i;
            break;
        }
    }

    cout << big << endl;
    cout << small << endl;
    system("pause");
    return 0;
}