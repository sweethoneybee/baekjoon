#include <iostream>
using namespace std;

int fibo(int a)
{
    // if(a < 2)
    // {
    //     return a;
    // }
    if(a == 1)
    {
        return 1;
    }
    else if(a == 0)
    {
        return 0;
    }
    else
    {
        return fibo(a-1) + fibo(a-2);
    }
    

}
int main(void)
{
    int n;
    cin >> n;

    cout << fibo(n);
    system("pause");
    return 0;
}