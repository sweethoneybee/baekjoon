#include <iostream>
using namespace std;

int main(void)
{
    int price = 0 ;
    cin >> price;

    int sum = 0;
    int book[9] = {0};
    for(int i = 0 ; i < 9; i++)
    {
        cin >> book[i];
        sum += book[i];
    }

    cout << price - sum;
    system("pause");
    return 0;
}