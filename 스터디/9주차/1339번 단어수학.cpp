#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v[11];
int alphabet_value[26] = {0};
int N;
int answer[11] = {0};

int main(void)
{
    cin >> N;
    
    vector<int> t;
    for(int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        int n = a.length();
        for(int j = 0; j < a.length(); j++)
        {
            v[n].push_back(a[j]);
            n -= 1;
        }
    }

    int n_v = 9;
    for(int i = 10; i >= 1; i--)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(alphabet_value[v[i][j] - 'A'] == 0)
            {
                alphabet_value[v[i][j] - 'A'] = n_v;
                n_v--;
            }

            answer[i] += alphabet_value[v[i][j] - 'A'];
        }
    }
    system("pause");
    return 0;
}