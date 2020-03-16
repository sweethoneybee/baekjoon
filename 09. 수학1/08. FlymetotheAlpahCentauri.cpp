#include <iostream>
using namespace std;

int main(void)
{
    int T, x, y;
    cin >> T;

    for(int t = 0; t < T; t++)
    {
        cin >> x >> y;
        int result = 0;
        int m = 0; // 총 거리
        m = y - x;
        if(m < 5)
        {
            if(m == 1) result = 1;
            else if(m == 2) result = 2;
            else if(m == 3) result = 3;
            else if(m == 4) result = 4;
        }
        else
        {
            int N, n;
            N = y - x - 2;
            if(N % 2 == 0)
            {
                int count1 = 0;
                int distance = 0;
                n = N/2;
                for(int i = 1;;i++)
                {
                    count1++;
                    distance += i;
                    if(distance >= n) break;
                }

                distance = 0;
                int count2 = 0;
                for(int i = 2;;i++)
                {
                    count2++;
                    distance += i;
                    if(distance >= n) break;
                }
                if(count1 < count2)
                {
                    cout << "count1 < count2" << endl;
                    result = count1 * 2 + 2;
                }
                else if(count2 <= count1)
                {
                    cout << "count2 <= count1" << endl;
                    cout << "count2 : " << count2 << endl;
                    result = count2 * 2 + 2;
                }
                
            }
            else
            {
                int count1 = 0;
                int distance = 0;
                n = (N-1) / 2;
                for(int i = 1;;i++)
                {
                    count1++;
                    distance += i;
                    if(distance >= n) break;
                }

                distance = 0;
                int count2 = 0;
                for(int i = 2;;i++)
                {
                    count2++;
                    distance += i;
                    if(distance >= n) break;
                }
                if(count1 < count2)
                {
                    result = count1 * 2 + 2 +1;
                }
                else if(count2 <= count1)
                {
                    result = count2 * 2 + 2 + 1;
                }
                
            }
        }

        cout << result << endl;
    }
     
    system("pause");
    return 0;
}