#include <iostream>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[21][21] = {0};
int R, C;
int max1 = -1;
int how = 0;
bool boolChk[100] = {0};

void Dfs(int x, int y, int count);
bool Chk(int x, int y);

int main(void)
{
    cin >> R >> C;
    for(int i = 1; i <= R; i++)
    {
        string input;
        cin >> input;
        for(int j = 0; j < C; j++)
        {
            board[i][j+1] = input[j];  
        }
    }

    boolChk[board[1][1]] = 1;
    int count = 0;
    count++;
    Dfs(1, 1, count);


    cout << max1;
    cout << "\nhow : " << how;
    system("pause");
    return 0;
}
void Dfs(int x, int y, int count)
{
    how++;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(Chk(nx, ny) && boolChk[board[nx][ny]] != 1)
        {
            boolChk[board[nx][ny]] = 1;
            Dfs(nx, ny, count+1);
            boolChk[board[nx][ny]] = 0;
           
        }
    }

    if(max1 < count)
    {
        max1 = count;
    }
}
bool Chk(int x, int y)
{
    if(x >=1 && x <= R && y >= 1 && y <=C)
    {
        return true;
    }
    else
    {
        return false;
    }
}