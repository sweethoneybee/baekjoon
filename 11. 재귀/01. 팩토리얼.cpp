#include <iostream>
using namespace std;

int factorial(int n)
{
    
    if(n == 0) return 1;
    return n * factorial(n-1);
}
int main(void)
{
    int a;
    cin >> a;

    cout <<  factorial(a);
    
    system("pause");
    return 0;
}