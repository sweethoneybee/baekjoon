#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int T;
    cin >> T;

    for(int i =0; i < T; i++)
    {
        int R;
        cin >> R;
        string chars;
        string i_chars;
        cin >> chars;

        i_chars = "";
        
        for(int j = 0; j < chars.length(); j++)
        {
            for(int k = 0; k < R; k++)
            {
                i_chars += chars[j];
            }
        }

        cout << i_chars << endl;   
    }

    system("pause");
    return 0;
}