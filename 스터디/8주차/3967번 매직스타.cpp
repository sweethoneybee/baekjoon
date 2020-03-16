#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> cor;
int input[5][9] = {0};
bool used[12] = {0};
bool chk = 0;
bool Chk();
int main(void)
{
    for(int i =0; i < 5; i++)
    {
        string a;
        cin >> a;
        for(int j = 0; j<9; j++)
        {
            input[i][j] = a[j];
            if(input[i][j] == 'x')
            {
                cor.push_back(make_pair(i, j));
            }
            if(input[i][j] >= 'A' && input[i][j] <= 'L')
            {
                used[input[i][j] - 'A'] = 1;
            }
        }
    }

    vector<int> a;
    for(int i = 0; i < 12; i++)
    {
        if(used[i] == 0)
            a.push_back(i);
    }
    
    do
    {
        int size = cor.size();
        int t_size = a.size();
        int j = 0;
        for(int i = 0; i < size; i++)
        {
            input[cor[i].first][cor[i].second] = a[i] + 'A';
        }

        if(Chk()) break;
    } while (next_permutation(a.begin(), a.end()));
    
    // int t_used[12] = {0};
    // do
    // {
    //     for(int i = 0; i < 12; i++)
    //     {
    //         t_used[i] = used[i];
    //     }
    //     int size = cor.size();
    //     for(int i = 0; i < size; i++)
    //     {
    //         for(int j = 0; j < 12; j++)
    //         {
    //             if(t_used[j] == 0)
    //             {
    //                 input[cor[i].first][cor[i].second] = j + 'A';
    //                 t_used[j] = 1;
    //                 break;
    //             }
    //         }
    //     }

    //     if(Chk()) break;
    // } while (next_permutation(cor.begin(), cor.end()));
    

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << char(input[i][j]);
        }
        cout << endl;
    }

    
    system("pause");
    return 0;
}

bool Chk()
{
    if
    (
        (input[0][4] - 'A' + input[1][3] - 'A' + input[2][2] - 'A' + input[3][1] - 'A' + 4) == 26 &&
        (input[0][4] - 'A' + input[1][5] - 'A' + input[2][6] - 'A' + input[3][7] - 'A' + 4) == 26 &&
        (input[1][1] - 'A' + input[1][3] - 'A' + input[1][5] - 'A' + input[1][7] - 'A' + 4) == 26 &&
        (input[1][1] - 'A' + input[2][2] - 'A' + input[3][3] - 'A' + input[4][4] - 'A' + 4) == 26 &&
        (input[3][1] - 'A' + input[3][3] - 'A' + input[3][5] - 'A' + input[3][7] - 'A' + 4) == 26 &&
        (input[1][7] - 'A' + input[2][6] - 'A' + input[3][5] - 'A' + input[4][4] - 'A' + 4) == 26
    )
    {
        return true;
    }
    else
    {
        return false;
    }
    
}