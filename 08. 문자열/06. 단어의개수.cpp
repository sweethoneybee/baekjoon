#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string words;
    getline(cin, words);

    int spaceCount = 0;
    for(int i = 0; i < words.length();i++)
    {
        if(words[i] == ' ')
        {
            spaceCount++;
        }
    }
    if(words[0] == ' ')
    {
        spaceCount--;
    }

    if(words[words.length()-1] == ' ')
    {
        spaceCount--;
    }

    spaceCount++;

    cout << spaceCount;
    system("pause");
    return 0;
}