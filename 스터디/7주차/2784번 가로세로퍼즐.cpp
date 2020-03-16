#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> word;

int main(void)
{
    for(int i = 0; i < 6; i++)
    {
        string a;
        cin >> a;
        word.push_back(a);
    }

    vector<vector<string>> answer;
    sort(word.begin(), word.end());
    do
    {
        vector<string> temp;
        int i = 0;
        temp.push_back(word[0]);
        temp.push_back(word[1]);
        temp.push_back(word[2]);

        string a = temp[0].substr(0, 1) + temp[1].substr(0, 1) + temp[2].substr(0, 1);
        string b = temp[0].substr(1, 1) + temp[1].substr(1, 1) + temp[2].substr(1, 1);
        string c = temp[0].substr(2, 1) + temp[1].substr(2, 1) + temp[2].substr(2, 1);

        if(a == word[3] && b == word[4] && c == word[5])
        {
            answer.push_back(temp);
            break;
        }
    } while (next_permutation(word.begin(), word.end()));
    
    if(answer.empty() != true)
    {
        for(int i = 0; i < 3; i++)
        {
            cout << answer[0][i] << endl;
        }
    }
    else
    {
        cout << 0;
    }
    
    system("pause");
    return 0;
}