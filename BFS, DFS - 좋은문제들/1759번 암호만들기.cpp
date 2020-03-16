#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int lenLimit = 4;

string moeum = "aeiou";
string sentense;
vector<string> answer;
int L, C;
void make(string sen, int idx);
void Print(vector<string>& vec);
bool Chk(string sen);
int main(void)
{
    string input;
    cin >> L >> C;
    for(int i = 0; i < C; i++)
    {
        cin >> input;
        sentense.append(input);
    }
    sort(sentense.begin(), sentense.end(), less<char>());

    for(int i = 0; i <= sentense.length() - L; i++)
    {
        string a = sentense.substr(i, 1);
        make(a, i+1);
    }
    Print(answer);

    system("pause");
    return 0;
}


void make(string sen, int idx)
{
    if(sen.length() == L)
    {
        
        if(Chk(sen))
        {
            answer.push_back(sen);
            return;
        }
    }
    else
    {
        for(int i = idx; i < sentense.length() ; i++)
        {
            make(sen + sentense.substr(i, 1), i+1);
        }
    }
    
}


void Print(vector<string>& vec)
{
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << (*i) << "\n";
    }
}

bool Chk(string sen)
{
    string a;
    int mCount = 0;
    int jCount = 0;
    for(int i = 0; i < sen.length(); i++)
    {
        a = sen[i];
        if(moeum.find(a) != string::npos)
        {
            mCount++;
        }
        else
        {
            jCount++;
        }
        
    }

    if(mCount >= 1 && jCount >=2)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}