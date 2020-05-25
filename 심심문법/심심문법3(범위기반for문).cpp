#include <iostream>
using namespace std;

int main(void)
{
    int arr[10];
    fill_n(arr, 10, 0);
    
    for(auto &n : arr)
    {
        n = 1;
    }
    for(auto &n : arr)
    {
        cout << n << endl;
    }
    system("pause");
    return 0;
}