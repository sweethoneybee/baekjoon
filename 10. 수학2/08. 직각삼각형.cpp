#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    double a, b, c;
    cin >> a >> b >> c;
    
    while(a+b+c != 0)
    {
        a = pow(a, 2);
        b = pow(b, 2);
        c = pow(c, 2);

        bool isRight = 0;
        if(a + b == c) isRight = 1;
        else if(a + c == b) isRight = 1;
        else if(b + c == a) isRight = 1;

        if(isRight == 1) cout << "right" << "\n";
        else cout << "wrong" << "\n";
        cin >> a >> b >> c;
    }
    system("pause");
    return 0;
}