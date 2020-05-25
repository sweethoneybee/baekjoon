#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream rf;

int N, answer;
pair<int ,int> rodAnswer;
vector<int> p, r;

int rodCutting(const vector<int> &p, int n, vector<int> &r);
int max(int a, int b);
int main(void)
{
    rf.open("input2-1.txt");

    rf >> N;
    int temp;
    p.push_back(0); // for indexing
    for(int i = 0; i < N; i++)  // set rod cutting value.
    {
        rf >> temp;
        p.push_back(temp);
    }

    for(int i = 0; i < N + 1; i++) // r is vector for DP.
    {
        r.push_back(-1);
    }

    answer = rodCutting(p, N, r);   // get Maximum value for N.

    cout << answer << endl;
    if(rodAnswer.first < rodAnswer.second)
    {
        if(rodAnswer.first != 0)
            cout << rodAnswer.first << " ";
        cout << rodAnswer.second << endl;
    }
    else
    {
        if(rodAnswer.second != 0)
            cout << rodAnswer.second << " ";
        cout << rodAnswer.first << endl;
    }
    
    rf.close();
    //system("pause");
    return 0;
}
int rodCutting(const vector<int> &p, int n, vector<int> &r)
{
    int q, temp;
    if(r[n] >= 0)
        return r[n];
    if(n == 0)
        q = 0;
    else
    {
        q = -1;
        temp = -1;
        for(int i = 1; i <= n; i++)
        {
            q = max(q, p[i] + rodCutting(p, n - i, r)); // finding max cutting value in length n.
            if(temp < q)        // found max value cutting length.
            {
                temp = q;
                rodAnswer.first = i;
                rodAnswer.second = n - i;
            }
        }
    }
    r[n] = q;       // optimization
    return q;
}
int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}