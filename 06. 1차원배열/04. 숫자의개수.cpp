#include <iostream>
using namespace std;

int main(void)
{
    int A, B, C, result;
    int count[10] = {0};
    
    cin >> A >> B >> C;
    result = A * B * C;

    while(result > 0)
    {
        count[result % 10] += 1;
        result /= 10;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << count[i] << endl;
    }

    system("pause");
    return 0;
}