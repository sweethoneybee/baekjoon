#include <iostream>
using namespace std;

int main(void)
{
    int A, B;
    cin >> A;
    cin >> B;

    if( A > B)
    {
        cout << ">" << endl;
    }
    else if(A < B)
    {
        cout << "<" << endl;
    }
    else
    {
        cout << "==" << endl;
    }
    system("puase");
    return 0;
}