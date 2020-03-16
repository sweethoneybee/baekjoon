#include <iostream>
#include <math.h>
#define M_PI 3.1415926535897932384
using namespace std;

int main(void)
{
    double R;
    cin >> R;

    cout << fixed;
    cout.precision(6);
    cout << M_PI * R * R << "\n";
    cout << pow(R,2) + pow(R,2);
    
    
    system("pause");
    return 0;
}