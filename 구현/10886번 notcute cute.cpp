#include <iostream>
using namespace std;

int main(void)
{
    int N; cin >> N;
    int count = 0;
    for(int i = 0; i < N; i++)
    {
        int a = 0;
        cin >> a;
        if(a == 1)
        {
            count++;
        }
    }

    N -= count;

    if(count > N)
    {
        cout << "Junhee is cute!";
    }
    else
    {
        cout << "Junhee is not cute!";
    }
    
    system("pause");
    return 0;
}