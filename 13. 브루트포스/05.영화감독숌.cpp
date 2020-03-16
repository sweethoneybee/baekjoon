#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int number = 666;
    int i =0;
    while(i<N)
    {
        int isSixContinue = 0;
        int i_number = number;

        while(i_number > 0)
        {
            if(isSixContinue < 3)
            {
                if(i_number % 10 == 6)
                {
                    isSixContinue++;
                }
                else
                {
                    isSixContinue = 0;
                }
            }
            i_number /= 10;
        }

        if(isSixContinue == 3)
        {
            i++;
        }
        number++;
    }

    cout << --number;
    cin >> N;
    return 0;
}


