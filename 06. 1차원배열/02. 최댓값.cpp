#include <iostream>
using namespace std;

int main(void)
{
    int N[9];
    int max = -1;
    int rank = 0;

    for(int i = 0; i < 9; i++)
    {
        cin >> N[i];
    }
    for(int i = 0; i < 9; i++)
    {
        if(max < N[i])
        {
            max = N[i];
            rank = i;
        }
    }



    cout << max << endl;
    cout << ++rank;
    system("pause");
    return 0;
}