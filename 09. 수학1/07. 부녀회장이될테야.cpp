#include <iostream>
using namespace std;

int main(void)
{
    int T, k, n;
    cin >> T;

    for(int t = 0; t < T; t++)
    {
        cin >> k >> n;
        int apart[k+1][n] = {0};
        for(int i = 0; i < n; i++)
        {
            apart[0][i] = i+1;
        }

        
        for(int i = 1; i < k+1; i ++)
        {
            for(int j = 0; j < n; j++)
            {
                int sum = 0;
                for(int l = 0; l < j+1; l++)
                {
                    sum += apart[i-1][l];
                }
                apart[i][j] = sum;
            }
        }
        
        cout << apart[k][n-1] << endl;
    }
    system("pause");
    return 0;
}