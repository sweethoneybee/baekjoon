#include <iostream>
using namespace std;

int main(void)
{
    int pointX[4] = {0};
    int pointY[4] = {0};

    for(int i = 0; i < 3; i++)
    {
        cin >> pointX[i];
        cin >> pointY[i];
    }
    int indexX, indexY, isDifferent, x, y;
    x = pointX[0];
    isDifferent = 0;
    for(int i = 1; i < 3; i++)
    {
        if(x != pointX[i]) 
        {
            indexX = i;
            isDifferent++;
        }
    }
    if(isDifferent == 1)
    {
        pointX[3] = pointX[indexX];
    }
    else
    {
        pointX[3] = x;
    }
    
    y = pointY[0];
    isDifferent = 0;
    for(int i = 1; i < 3; i++)
    {
        if(y != pointY[i]) 
        {
            indexY = i;
            isDifferent++;
        }
    }
    if(isDifferent == 1)
    {
        pointY[3] = pointY[indexY];
    }
    else
    {
        pointY[3] = y;
    }
    
    cout << pointX[3] << " "<< pointY[3]; 
    system("pause");
    return 0;
}