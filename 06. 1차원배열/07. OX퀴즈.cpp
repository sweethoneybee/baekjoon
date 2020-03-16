#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    string testcase[N];
    int result[N] = {0};
    for(int i = 0; i < N; i++)
    {
        cin >> testcase[i];
    }

    for(int i = 0; i< N; i++)
    {
        int count = 1;
        int max = 0;
        for(int j = 0; j < testcase[i].length(); j++)
        {
            if(testcase[i][j] == 'O')
            {
                max += count;
                count++;
            }
            else
            {
                count = 1;
            }
        }

        result[i] = max;
    }
    
    
    for(int i = 0; i< N; i++)
    {
        cout << result[i] << endl;
    }


    system("pause");
    return 0;
}