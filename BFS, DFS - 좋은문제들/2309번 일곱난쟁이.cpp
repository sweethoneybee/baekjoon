#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dwarf;
vector<int> realAnswer;
void find(vector<int> answer, int sum, int index, int count);
void Print(vector<int> answer);
int main(void)
{
    int a;
    for(int i = 0; i < 9; i++)
    {
        cin >> a;
        dwarf.push_back(a);
    }

    for(int i = 0; i < 9 - 6; i++)
    {
        vector<int> answer;
        int sum = 0;
        int index = i;
        int count = 0;

        answer.push_back(dwarf[i]);
        sum += dwarf[i];
        index += 1;
        count++;

        find(answer, sum, index, count); 
    }

    sort(realAnswer.begin(), realAnswer.end());
    Print(realAnswer);
    system("pause");
    return 0;
}

void find(vector<int> answer, int sum, int index, int count)
{
    if(count == 7)
    {
        if(sum == 100)
        {
            realAnswer = answer;
        }
    }
    else
    {
        for(int i = index; i < 9; i++)
        {
            vector<int> temp = answer;
            temp.push_back(dwarf[i]);
            find(temp, sum + dwarf[i], i+1, count+1);
        }
    }
    
}

void Print(vector<int> answer)
{
    for(auto i = answer.begin(); i != answer.end(); i++)
    {
        cout << (*i) << "\n";
    }
}