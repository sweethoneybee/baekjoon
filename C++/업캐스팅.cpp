#include <iostream>
using namespace std;
class Animal
{
public:
    int a;
    virtual void printHello()
    {
        cout << "printHello()" << endl;
    }
    
private:

};

class Person : public Animal
{
    public:
    int b;
    virtual void printWow()
    {
        cout << "printWow()" << endl;
    }
};
int main(void)
{

    Animal* temp = new Person();
    dynamic_cast<Person*>(temp)->printWow();

    delete temp;
    system("pause");
    return 0;
}