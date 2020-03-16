#include <iostream>
using namespace std;

int main(void)
{
    int eat[3] = {0};
    int drink[2] ={0};
    for(int i = 0; i < 3; i++)
    {
        cin >> eat[i];
    }
    for(int i = 0; i < 2; i++)
    {
        cin >> drink[i];
    }

    int min_eat = 500000;
    int min_drink = 50000;
    for(int i = 0; i < 3; i++)
    {
        if(min_eat > eat[i])
            min_eat = eat[i];
    }
    for(int i = 0 ; i< 2; i++)
    {
        if(min_drink > drink[i])
            min_drink = drink[i];
    }

    cout << min_eat + min_drink - 50;
    system("pause");
    return 0;
}