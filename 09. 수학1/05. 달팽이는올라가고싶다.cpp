#include <iostream>
using namespace std;

int main(void)
{
    int A, B ,V;
    cin >> A >> B >> V;

    int day = 0;

    day = (V - A) / (A-B);
    if((V-A) > day * (A-B)) day+= 1;
    day += 1;
    cout << day;
    system("pause");
    return 0;
}