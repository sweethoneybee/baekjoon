#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int K; int count;
vector<pair<int, int>> answer;
void hanoi(int from, int temp, int to, int n, int* arr);
void bigNum(vector<int>& answer, int K);
int main(void)
{
    cin >> K;
    int* arr = new int[K];
    fill_n(arr, K, 0);
    arr[0] += K;
    
    if(K <= 20)
    {
        hanoi(0, 1, 2, K, arr);
        cout << count << endl;
        for(auto i = answer.begin(); i != answer.end(); i++)
        {
            cout << i->first+1 << " " << i->second+1 << "\n";
        }
    }
    else
    {
    
        vector<int> num(1, 1);
        bigNum(num, K);

        auto i = num.rbegin();
        for(; i != num.rend() - 1; i++)
        {
            cout << (*i);
        }
        cout << (*i) - 1;
        
    }

    
    system("pause");
    return 0;
}
void bigNum(vector<int>& answer, int K)
{
    while( K != 0)
    {
        for(auto i = answer.begin(); i != answer.end(); i++)
        {
            (*i) *= 2;
        }

        auto i = answer.begin();
        for(; i != answer.end() - 1; i++)
        {
            if((*i) >= 10)
            {
                (*i) %= 10;
                if(i == answer.end() -1)
                {
                    answer.push_back(1);
                }
                else
                {
                    *(i+1) += 1;
                }
                
            }
        }
        if((*i) >= 10)
        {
            (*i) %= 10;
            answer.push_back(1);
        }

        K--;
    }
}
void hanoi(int from, int temp, int to, int n, int* arr)
{
    if(n <= 1)
    {
        answer.push_back(make_pair(from, to));
        arr[from]--;
        arr[to]++;
        //cout << arr[0] << arr[1] << arr[2] << endl;
        count++;
    }
    else
    {
        hanoi(from, to, temp, n-1, arr);
        arr[from] -= 1; arr[to] += 1;
        answer.push_back(make_pair(from, to));
        //cout << arr[0] << arr[1] << arr[2] << endl;
        count++;
        hanoi(temp, from, to, n-1, arr);
    }
    
}
