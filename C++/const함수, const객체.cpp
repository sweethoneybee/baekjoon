#include <iostream>
using namespace std;

class C
{
public:
    int x, y;

    C(int x, int y) : x(x), y(y){}
    int get1();
    int get2()const;

};

int C::get1()
{
    cout << "일반 함수 호출!\n";
    return x;
}

int C::get2() const
{
    cout << "const 함수 호출!\n";
    return x;
}


int main(void)
{
    const int* a;
    int* A, B;
    //int* const b;
    
    //C widget(1, 2);
    const C widget(1, 2);
    //widget.get1();
    widget.get2();

    system("pause");
    return 0;
}