#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int a[10][10] = {0};

    fill_n(a[0], 100, 1);
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    cout <<"\n";
    vector<vector<int>> b;
    
    for(int i = 0; i < 5; i++)
    {
        vector<int> input;
        for(int j = 0; j < 5; j++)
        {
            int c;
            cin >> c;
            input.push_back(c);
        }
        b.push_back(input);
    }
    for(int i = 0; i < b.size(); i++)
    {
        for(int j = 0; j < b[i].size(); j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }

    system("pause");
    return 0;
}