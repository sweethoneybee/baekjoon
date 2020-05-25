#include <iostream>
#include <string>
using namespace std;

class NoVirtual
{
    int a;
public:
    void x() const{};
    int i() const {return 1;};
};
class OneVirtual
{
    double a;
public:
    virtual void x() const{};
    int i() const {return 1;};
};
class TwoVirtual
{
    double a;
public:
    virtual void x() const{};
    virtual int i() const {return 1;};
    virtual void b() const{};
    virtual void c() const{};
    virtual void d() const{};
    virtual void e() const{};
    virtual void f() const{};
    virtual void g() const{};
    virtual void h() const{};
};
int main(void)
{
    cout << "int : " << sizeof(int) << endl;
    cout << "NoVirtual: " << sizeof(NoVirtual) << endl;
    cout << "void* : " << sizeof(void*) << endl;
    cout << "OneVirtual: " << sizeof(OneVirtual) << endl;
    cout << "TwoVirtuals: " << sizeof(TwoVirtual) << endl;
    OneVirtual temp1;
    TwoVirtual temp2;

    cout << "OneVirtual instance : " << sizeof(temp1) << endl;
    cout << "TwoVirtual instance : " << sizeof(temp2) << endl;

    system("pause");
    return 0;
}