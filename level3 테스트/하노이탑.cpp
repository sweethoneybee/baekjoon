#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    int top[3][16] = {0};
    top[0][0] = 20;
    top[1][0] = 20;
    top[2][0] = 20;
    int index[3] = {0};
    
    int idx = 1;
    for(int i = n; i >= 1; i--)
    {
        top[0][idx] = n;
        idx++;
    }
    
    index[0] += n;
    while(index[2] != n)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(index[2] == n ) break;
                if(index[i] > 0)
                {
                    int temp = top[i][index[i]];
                    if( i != j && temp < top[j][index[j]])
                    {
                        top[j][index[j]+1] = temp;
                        index[j]++;
                        index[i]--;
                        j=0;
                    }
                }
            }
        }
    }
    return answer;
}