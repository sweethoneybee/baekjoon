#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream rf;

int nums[501][501] = {0};
int arrows[501][501] = {0};
string x, y, answer;
int x_len, y_len;

int findMaxAndMakeArrows(int i, int j);
int main(void)
{
    rf.open("input2-2.txt");
    rf >> x;    // longer one
    rf >> y;    // shorter one
    x_len = x.length();
    y_len = y.length();

    for(int i = 1; i <= x_len; i++)
    {
        for(int j = 1; j <= y_len; j++)
        {
            if(x.substr(i - 1, 1).compare(y.substr(j - 1, 1)) != 0) // not same char
            {
                nums[i][j] = findMaxAndMakeArrows(i, j);
            }
            else    // same char
            {
                nums[i][j] = nums[i-1][j-1] + 1;
                arrows[i][j] = 2;            // diagonal
            }
        }
    }

    answer = ""; 
    while(x_len > 0 && y_len > 0)
    {
        if(arrows[x_len][y_len] == 0) // left arrow
        {
            y_len--;
        }
        else if(arrows[x_len][y_len] == 1) // up arrow
        {
            x_len--;
        }
        else if(arrows[x_len][y_len] == 2) // diagonal arrow
        {
            answer += x.substr(x_len-1, 1);
            x_len--;
            y_len--;
        }
    }
    
    int size = answer.length();
    for(auto i = answer.rbegin(), rend = answer.rend(); i != rend; i++)
    {
        cout << (*i);
    } 
    cout << endl;
    rf.close();
    //system("pause");
    return 0;
}
int findMaxAndMakeArrows(int i, int j)
{
    if(nums[i-1][j] >= nums[i][j-1])    // if left and up values are same, choose up one.
    {
        arrows[i][j] = 1;        // up arrow
        return nums[i-1][j];
    }
    else
    {
        arrows[i][j] = 0;       // left arrow
        return nums[i][j-1];
    }
}