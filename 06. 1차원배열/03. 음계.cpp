#include <iostream>
using namespace std;

int abs(int num)
{
    if(num < 0)
    {
        num = -num;
    }

    return num;
}

int main(void)
{
    int scale[9];
    for(int i =1; i <= 8; i++)
    {
        cin >> scale[i];
    }

    if( scale[1] == 1)
    {
        int compare = scale[1];
        for(int i = 1; i <=8; i++)
        {
            if(compare != scale[i])
            {
                cout << "mixed";
                break;
            }
            compare++;
        }

        if(compare == 9)
        {
            cout << "ascending";
        }
    }
    else if(scale[1] == 8)
    {
        int compare = scale[1];
        for(int i = 1; i <=8; i++)
        {
            if(compare != scale[i])
            {
                cout << "mixed";
                break;
            }
            compare--;
        }

        if(compare == 0)
        {
            cout << "descending";
        }
    }
    else
    {
        cout << "mixed";
    }
    
    

    system("pause");
    return 0;
}