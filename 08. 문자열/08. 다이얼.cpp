#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string words;
    cin >> words;

    int time[26] = {0};
    int needTime = 3;
    for(int i =0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            time[3 * i + j] = needTime; 
        }
        needTime++;
    }

    for(int i = 0; i < 4; i++)
    {
        time[3 * 5 + i] = needTime;
    }
    needTime++;

    for(int i = 0; i < 3; i++)
    {
        time[3 * 6 + 1 + i] = needTime;
    }
    needTime++;

    for(int i = 0; i < 4; i++)
    {
        time[3 * 7 + 1 + i] = needTime;
    }
    

    int timeSum = 0;
    for(int i = 0; i < words.length(); i++)
    {
        timeSum += time[words[i] - 'A'];
    }

    cout << timeSum;
    system("pause");
    return 0;
}