#include <iostream>
using namespace std;

int main(void)
{
    int day = 0 ;
    int car[5] = {0};
    int answer = 0;
    cin >> day;

    for(int i = 0; i < 5; i++)
    {
        cin >> car[i];
        if(car[i] == day)
        {
            answer++;
        }
    }
    cout << answer;
    system("pause");
    return 0;
}