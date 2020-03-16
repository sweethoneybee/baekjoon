#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    string words[N];
    for(int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    
    int count = N;
    for(int i = 0; i< N; i++)
    {  
        bool isFirst[26] = {0};
        for(int j = 0; j < words[i].length(); j++)
        {
            if(isFirst[words[i][j] - 'a'] != 0)
            {
                count--;
                break;
            }

            if(isFirst[words[i][j] - 'a'] == 0)
            {
                isFirst[words[i][j] - 'a'] = 1;
                int temp = j;
                for(int k = 1; k < words[i].length()-temp;k++)
                {
                    if(words[i][j] != words[i][j+1])
                    {
                        break;
                    }
                    j++;
                }
            }       



        }
    }

    cout << count;

    system("pause");
    return 0;
}