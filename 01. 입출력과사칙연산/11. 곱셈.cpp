#include <iostream>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    int M_digit[3];
    int result[4] = {0};

    int i_M = M;
    for(int i = 0; i < 3; i++)
    {
        M_digit[i] = i_M % 10;
        i_M /= 10;
    }

    int a = 1;
    for(int i = 0; i < 3; i++)
    {
        result[i] = N * M_digit[i];
        
        result[3] += N * M_digit[i] * a;
        a*=10;
    }

    
    for(int i =0; i < 4; i++)
    {
        cout << result[i] << endl;
    }
    system("pause");
    return 0;
}