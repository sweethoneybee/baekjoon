#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> widget;
    for(int i = 1; i <= 4; i++)
    {
        widget.push_back(i);
    }

    // widget[0] = 4;
    // widget[3] = 1;
    cout << "widget : ";
    for(int i = 0; i <= 3; i++)
    {
        cout << widget[i] << " ";
    }
    cout << "\n";

    while(next_permutation(widget.begin(), widget.end())){

        cout << "after permu, widget : ";
        for(int i = 0; i <= 3; i++)
        {
            cout << widget[i] << " ";
        }
        cout << "\n";

    };

    system("pause");
    return 0;
}