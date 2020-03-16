#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    // A : 65, a : 97
    string word;
    int count[26] = {0};
    cin >> word;

    for(int i = 0; i < word.length(); i++)
    {
        if(int(word[i]) < 96)
        {
            count[int(word[i]) + 32 - 97]++;
        }
        else
        {
            count[word[i]-97]++;
        }
    }

    int result;
    int max = -1;
    int maxResult;
    bool isMax;
    for(int i =0; i < 26; i++)
    {
        if(max < count[i])
        {
            max = count[i];
            maxResult = i;
            isMax = 1;
        }
        else if(max == count[i])
        {
            isMax = 0;
        }
    }

   
    result = maxResult+65;
    if(isMax == false)
    {
        cout << '?';
    }
    else 
    {    
        cout << char(result);
    }


    system("pause");
    return 0;
}