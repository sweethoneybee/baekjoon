#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N; 
    cin >> N;

    string sum = "";

    if(N % 2 == 0)
    {
        while(N!=0)
        {
            sum += "1";
            N -= 2;
        }    
    }
    else
    {
        while(N!=3)
        {
            sum += "1";
            N -= 2;
        }

        sum += "7";
    }

    for(auto i = sum.rbegin(); i != sum.rend(); i++)
    {
        cout << *i;
    }
    cout << "\n";
    system("pause");
    return 0;
}