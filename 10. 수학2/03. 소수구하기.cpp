#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(void)
{
    int N, M;
    cin >> M >> N;
    int num[N+1];
    for(int i = 1; i <= N; i++)
    {
        num[i] = i;
    }

    num[1] = 0;
    for(int i = 2; i <= sqrt(double(N)); i++)
    {
        if(num[i] != 0)
        {
            int multipleNum = i;
            int multiple = 2;
            while(multipleNum * multiple <= N)
            {
                num[multipleNum * multiple] = 0;
                multiple += 1;
            }
        }
    }

    for(int i = M; i <= N; i++)
    {
        if(num[i] != 0)
            cout << num[i] << "\n";
    }
    system("pause");
    return 0;
}