#include <string>
#include <iostream>
using namespace std;


int Doub(int x)
{
    int result = 0;
    result = x * x;
    return result;
}

int Trip(int x)
{
    int result = x * x * x;
    return result;
}
int solution(string input) {
    int num[3] = {0}; int bonus[3] = {0}; int option[3] = {0};
    int minus[3] = {1, 1, 1};

    int numIndex = 0; int bonusIndex = 0;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] - '0' == 0 || input[i] - '0' >= 2 && input[i] - '0' <= 10)
        {
            num[numIndex] = input[i] - '0';
            numIndex++;
            continue;
        }
        else if(input[i] -'0' == 1)
        {
            num[numIndex] = input[i] - '0';
            if(input[i+1] - '0' == 0)
            {
                num[numIndex] *= 10;
                i++;
            }
            numIndex++;
            continue;

        }
        
        else if(input[i] == 'S' || input[i] == 'D' || input[i] == 'T')
        {
            bonus[bonusIndex] = input[i];
            bonusIndex++;
            continue;
        }

        else if(input[i] == '*' || input[i] == '#')
        {
            option[bonusIndex-1] = input[i];
            continue;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        if(bonus[i] == 'D')
            num[i] = Doub(num[i]);
        else if(bonus[i] == 'T')
            num[i] = Trip(num[i]);

        if(option[i] == '*')
        {
            num[i] = num[i] * 2;
            if(i > 0)
                num[i - 1] = num[i-1] *2;
        }
        else if(option[i] == '#')
        {
            minus[i] = -1;
        }

    }

    int answer = 0;
    for(int i = 0; i < 3; i++)
    {
        answer += num[i] * minus[i];
    }

    return answer;
}

int main(void)
{
    string a;
    cin >> a;
    int answer = solution(a);
    cout << answer;
    system("pause");
    return 0;
}