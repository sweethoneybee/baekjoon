#include <iostream>
using namespace std;

int main(void)
{
    long long A, B, C;
    cin >> A >> B >> C;
    
    long long result = -1;
    if(B < C)
    {
        result = A / (C-B) + 1;
    }

    cout << result;
    
    system("pause");
    return 0;
}