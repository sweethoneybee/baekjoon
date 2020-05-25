#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void dfs(const string &str, int &count);

// a가 앞에오는 것이 참이어야함.
bool compareLength(const string &a, const string &b)
{
    return a.length() <= b.length();
}
map<string, int> m;
int bigCount = -1;
int N;
int main(void)
{
    cin >> N;
    string *tmp = new string[N];
    for(int i = 0; i < N; i++)
    {
        cin >> tmp[i];
    }
    sort(tmp, tmp + N, compareLength);
    for(int i = 0; i < N; i++)
    {
        m[tmp[i]] = 1;
    }

    for(int i = 0; i < N; i++)
    {
        int count = 1;
        dfs(tmp[i], count);
    }    

    cout << bigCount;
    system("pause");
    return 0;
}

void dfs(const string &str, int &count)
{
    string tmp;
    for(int i = 0, size = str.length(); i < size; i++)
    {
        tmp = str.substr(0, i) + str.substr(i + 1, size -i - 1);
        if(m.find(tmp) != m.end())
        {
            if(m[tmp] == 1)
            {
                count++;
                dfs(tmp, count);
            }
            else if(m[tmp] > 1)
            {
                count += m[tmp];
            }
        }
    }
    if(count > bigCount)
    {
        bigCount = count;
    }
    count--;
}
