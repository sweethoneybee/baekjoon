#include <iostream>
using namespace std;

int main(void)
{
    int arr[4] = {0};
    string answer[3] = {};
    int index = 0;
    for(int i = 0; i < 3; i++)
    {
        int chk = 0;
        for(int j = 0; j < 4; j++)
        {
            cin >> arr[j];
            if(arr[j] == 0) chk++;
        }

        if(chk == 1) answer[index] = "A"; 
        else if(chk == 2) answer[index] = "B";
        else if(chk == 3) answer[index] = "C";
        else if(chk == 4) answer[index] = "D";
        else if(chk == 0) answer[index] = "E";
        index++;
    }

    for(int i = 0; i < 3; i++)
    {
        cout << answer[i] << "\n";

    }
    system("pause");
    return 0;
}