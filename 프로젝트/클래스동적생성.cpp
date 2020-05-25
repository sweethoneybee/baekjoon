#include <iostream>
using namespace std;

class C
{
public:
    C(int n)
    {
        cout << "-----start instruct C-----" << endl;
        num = new int(n);
        cout << "-----end instruct C-----" << endl;
    }
    ~C()
    {
        cout << "-----start destroy C------" << endl;
        delete num;
        cout << "-----end destroy C-----" << endl;
    }

    void printItem() const
    {
        cout << "num : " << *num << endl;
        return;
    }
private:
    int *num;
};
void func(int num)
{
    cout << "---start function---" << endl;
    C *temp = new C(2);
    temp->printItem();
    cout << "---end function---" << endl;

    delete temp;
}
int main(void)
{
    func(2);
    system("pause");
    return 0;
}