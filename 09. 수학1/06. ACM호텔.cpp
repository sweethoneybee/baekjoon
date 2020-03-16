#include <iostream>
using namespace std;

int main(void)
{
    int T, W, H, N, w, h;
    cin >> T;
    int result[T] = {0};
    for(int t = 0; t < T; t++)
    {
        cin >> H >> W >> N;

        int count = 0;
        for(int i = 1; i <= W; i++)
        {
            for(int j = 1; j <= H; j++)
            {
                count++;                
                if(N == count)
                {
                    h = j;
                    break;
                }
            }

            if(N == count)
            {
                w = i;
                break;
            }
        }
        result[t] = h * 100 + w;
    }

    for(int i = 0; i < T; i++)
    {
        cout << result[i] << endl;
    }
    system("pause");
    return 0;
}