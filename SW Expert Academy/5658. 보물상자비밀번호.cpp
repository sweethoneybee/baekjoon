#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, K, T;

int main(void)
{
    cin >> T;
    int ansNum = 1;
    for(int t = 0; t<T; t++)
    {
        vector<string> col;
        vector<int> answer;
        cin >> N >> K;
        int rotate = N / 4 - 1;
        int stride = N / 4;
        string box(N+rotate, ' ');
        string a; cin >> a;
        int aIndex = 0;
        for(int i = rotate; i < N+rotate; i++)
        {
            box[i] = a[aIndex++];
        }

        int end = box.size() -1;
        for(int i = rotate - 1 ; i >= 0; i--)
        {
            box[i] = box[end--];
        }

        int start = rotate;
        for(int i = 0; i <= rotate; i++)
        {
            for(int j = start; j < N; j += stride)
            {
                col.push_back(box.substr(j, stride));
            }
            start--;
        }
        
        
        int size = col.size();
        for(int i = 0; i < size; i++)
        {
            int digit = 1;
            for(int r = 0; r < stride - 1; r++)
            {
                digit *= 16;
            }

            int num = 0;
            int index = 0;
            while(digit != 0)
            {
                int k = 0;
                if(col[i][index] >= '0' && col[i][index] <= '9')
                {
                    k = col[i][index] - '0';
                }
                else
                {
                    k = col[i][index] - 'A' + 10;
                }
                
                num += digit * k;
                index++;
                digit /= 16;
            }
            
            answer.push_back(num);
        }

        sort(answer.begin(), answer.end(), greater<int>());
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
        
        cout << "#" << ansNum++ << " " << answer[K-1] << "\n";
     
    }
    system("pause");
    return 0;
}