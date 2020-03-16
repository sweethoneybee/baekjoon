#include <iostream>
using namespace std;

int main(void)
{
    int change = 0;
    int input = 0;
    cin >> input;
    input = 1000 - input;
    int index = 0;
    int changes[6] = {500, 100, 50, 10, 5, 1};

    while(input != 0)
    {
        if(input - changes[index] >= 0)
        {
            input -= changes[index];
            change += 1;
        }
        else
        {
            index++;
        }
        
    }

    cout << change;
    system("pause");
    return 0;
}