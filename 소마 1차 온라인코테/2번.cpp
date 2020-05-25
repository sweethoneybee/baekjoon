#include <iostream>
using namespace std;

int input[50][50] = {0};
int tile[50][50] = {0};
int N, M, T;
bool Chk(int x, int y);
void Color(int x, int y);
int main(void)
{
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        fill_n(input[0], 50 * 50, 0);
        fill_n(tile[0], 50 * 50, 0);
        cin >> N >> M;
        for(int i = 0 ; i < N ; i++)
        {
            for(int j = 0; j < M ; j++)
            {
                cin >> input[i][j];
            }
        }

        for(int i = 0; i <= N - 2; i++)
        {
            for(int j = 0; j <= M-2; j++)
            {
                if(Chk(i, j))
                {
                    Color(i, j);
                }
            }
        }

        bool answer = 1;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(input[i][j] != tile[i][j])
                {
                    answer = 0;
                    break;
                }
            }

            if(answer == 0) break;
        }

        
        if(answer == 1)
        {
            cout << "YES\n";
        }
        else if(answer == 0)
        {
            cout << "NO\n";
        }
    }
	
    system("pause");
    return 0;
}


bool Chk(int x, int y)
{
    if(input[x][y] == 1 && input[x+1][y] == 1 && input[x][y+1] == 1 && input[x+1][y+1] == 1)
    {
        return true;
    }

    else 
    {
        return false;
    }
}

void Color(int x, int y)
{
    tile[x][y] = 1;
    tile[x+1][y] = 1;
    tile[x][y+1] = 1;
    tile[x+1][y+1] = 1;
}

