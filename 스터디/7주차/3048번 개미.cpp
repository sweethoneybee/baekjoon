#include <iostream>
#include <string>
using namespace std;

string L = "";
string R = "";
int N1, N2, T;

int main(void)
{
    cin >> N1 >> N2;
    int* left = new int[N1];
    int* right = new int[N2];

    cin >> L;
    cin >> R;
    cin >> T;

    int num = 0;
    for(int i = N1 -1; i >= 0; i--)
    {
        left[i] = num;
        num += 2;
    }    
    num -= 1;
    for(int i = 0; i < N2; i++)
    {
        right[i] = num;
        num += 2;
    }

   
    for(int t = 0; t < T; t++)
    {
        for(int i = 0; i < N1; i++)
        {
            left[i] += 1;
        }
        for(int i = 0; i< N2; i++)
        {
            right[i] -= 1;
        }
    }

    string answer = "";

    int t_left = N1-1;
    int t_right = 0;
   
    for(int i = 0; i < N1 + N2; i++)
    {
        if(t_left == -1)
        {
            answer += R.substr(t_right, 1);
            t_right++;
        }
        else if(t_right == N2)
        {
            answer += L.substr(t_left, 1);
            t_left--;
        }
        else if(left[t_left] < right[t_right])
        {
            answer += L.substr(t_left, 1);
            t_left--;
        }
        else if(left[t_left] > right[t_right])
        {
            answer += R.substr(t_right, 1);
            t_right++;
        }
    }
    cout << answer << endl;
    system("pause");
    return 0;
}