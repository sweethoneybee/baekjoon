#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while(n != 0)
    {
        int n2 = 2 * n;

        int num[n2 + 1];
        for(int i = 1; i <= n2; i++)
        {
            num[i] = i;
        }
        num[1] = 0;
        for(int i = 2; i <= sqrt(double(n2)); i++)
        {
            if(num[i] != 0)
            {
                int multipleNum = i;
                for(int j = 2; multipleNum * j <= n2; j++)
                {
                    num[multipleNum * j] = 0;
                }
            }
        }

        int count = 0;
        for(int i = n+1; i <= n2; i++)
        {
            if(num[i] != 0)
                count++;
        }

        cout << count << "\n";

        cin >> n;
    }
  
    system("pause");
    return 0;
}