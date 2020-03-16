#include <iostream>
using namespace std;
class C
{
public:
    int num;

    C() : num(0){}
    C(int a) : num(a) {}
};
int main(void)
{
    C* c = new C();
    cout << c->num;

    system("pause");
    return 0;
}