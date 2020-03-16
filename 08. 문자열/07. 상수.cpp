#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string A, B;
    cin >> A;
    cin >> B;

    int a, b, digit;
    a = 0;
    b = 0;
    digit = 1;
    for(int i = 0; i < A.length(); i++)
    {
        a += (A[i] - '0') * digit;
        digit *= 10;
    }
    
    digit = 1;
    for(int i = 0; i < B.length(); i++)
    {
        b += (B[i] - '0') * digit;
        digit *= 10;
    }
    
    int max = a;
    if(a < b)
    {
        max = b;
    }
    
    cout << max;
    
    system("pause");
    return 0;
}