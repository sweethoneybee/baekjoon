#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    string nums;
    cin >> nums;

    int sum = 0;
    for(int i = 0; i < nums.length(); i++)
    {
        sum += nums[i] - '0';
    }
    cout << sum;
    system("pause");
    return 0;
}