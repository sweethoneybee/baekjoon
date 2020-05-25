#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> v;
    for(int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), [](int &a, int &b)->int{return a > b;});
        
    for(auto &n : v)
    {
        cout << n << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}