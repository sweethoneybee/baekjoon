#include <iostream>
using namespace std;

int main(void)
{
    string N;
    cin >> N;

    string croAlpha[8];

    croAlpha[0] = "dz=";
    croAlpha[1] = "c=";
    croAlpha[2] = "c-";
    croAlpha[3] = "d-";
    croAlpha[4] = "lj";
    croAlpha[5] = "nj";
    croAlpha[6] = "s=";
    croAlpha[7] = "z=";
   
    int count = 0;
    for(int i = 0; i < N.length(); i++)
    {
        int k = i;
        if(N.substr(i, 3) == croAlpha[0])
        {
            i+=2;
            count++;
        }

        for(int j = 1; j < 8; j++)
        {
            if(N.substr(i, 2) == croAlpha[j])
            {
                i++;
                count++;
                break;
            }
        }

        if(i == k)
        {
            count++;
        }
    }

    cout << count;

    system("pause");
    return 0;
}