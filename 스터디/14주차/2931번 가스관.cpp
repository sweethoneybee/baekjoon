#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<pair<int, int>> que;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int arr[26][26] = {0};
int visited[26][26] = {0};
int R, C;
pair<int, int> M, D;

bool chk(int x, int y);
void bfs();
int findWhatBlock(int x, int y);

char block[] = {'|', '-', '+', '1', '2', '3', '4'};
char answer;
int main(void)
{
    cin >> R >> C;
    string temp;
    for(int i = 1; i <= R; i++)
    {
        cin >> temp;
        for(int j = 1; j <= C; j++)
        {
            arr[i][j] = temp[j-1];
            if(temp[j-1] == 'M')
            {
                M.first = i;
                M.second = j;
                que.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }

    bfs();
    answer = block[findWhatBlock(D.first, D.second)];

    if(answer == -1)
    {
        cout << "ERROR!!!" << endl;
    }
    else
    {
        cout << D.first << " " << D.second << " " << answer;
    }
    
    system("pause");
    return 0;
}

bool chk(int x, int y)
{
    if(x >= 1 && x <= R && y >= 1 && y <= C) return true;
    else return false;
}

bool chkRightBlock(int x, int y)
{
    switch (arr[x][y])
    {
    case '|':
        if(arr[x + 1][y] == '.')
        {
            D.first = x + 1;
            D.second = y;
            return false;
        }
        else if(arr[x - 1][y] == '.')
        {
            D.first = x - 1;
            D.second = y;
            return false;
        }
        else
        {
            return true;
        }   
        break;
    case '-':
        if(arr[x][y + 1] == '.')
        {
            D.first = x;
            D.second = y + 1;
            return false;
        }
        else if(arr[x][y - 1] == '.')
        {
            D.first = x;
            D.second = y - 1;
            return false;
        }
        else
        {
            return true;
        }
        break;
    case '+':
        if(arr[x + 1][y] == '.')
        {
            D.first = x + 1;
            D.second = y;
            return false;
        }
        else if(arr[x - 1][y] == '.')
        {
            D.first = x - 1;
            D.second  = y;
            return false;
        }
        else if(arr[x][y + 1] == '.' )
        {
            D.first = x;
            D.second = y + 1;
            return false;
        }
        else if(arr[x][y - 1] == '.')
        {
            D.first = x;
            D.second = y - 1;
            return false;
        }
        else
        {
            return true;
        }
        break;
    case '1':
        if(arr[x + 1][y] == '.')
        {
            D.first = x + 1;
            D.second = y;
            return false;
        }
        else if(arr[x][y + 1] == '.')
        {
            D.first = x;
            D.second = y + 1;
            return false;
        }
        else
        {
            return true;
        }
        
        break;
    case '2':
        if(arr[x - 1][y] == '.')
        {
            D.first = x - 1;
            D.second = y;
            return false;
        }
        else if(arr[x][y + 1] == '.')
        {
            D.first = x;
            D.second = y + 1;
            return false;
        }
        else
        {
            return true;
        }
        
        break;
    case '3':
        if(arr[x - 1][y] == '.')
        {
            D.first = x - 1;
            D.second = y;
            return false;
        }
        else if(arr[x][y - 1] == '.')
        {
            D.first = x;
            D.second = y - 1;
            return false;
        }
        else 
        {
            return true;
        }
        break;
    case '4':
        if(arr[x + 1][y] == '.')
        {
            D.first = x + 1;
            D.second = y;
            return false;
        }
        else if(arr[x][y - 1] == '.')
        {
            D.first = x;
            D.second = y - 1;
            return false;
        }
        else 
        {
            return true;
        }
        break;
        
    default:
        break;
    }
}
void bfs()
{
    while(que.empty()!=true)
    {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(chk(nx, ny) && visited[nx][ny] == 0 && arr[nx][ny] != '.')
            {
                if(!chkRightBlock(nx, ny))
                {
                    return;
                }
                visited[nx][ny] = 1;
                que.push(make_pair(nx, ny));                
            }
        }
    }
}

int findWhatBlock(int x, int y)
{
    int sur[4] = {0};
    // 0 : 아래, 1 : 오른쪽, 2: 위, 3: 왼쪽
    for(int i = 0; i < 4; i++)
    {
        if(chk(x + dx[i], y + dy[i]) && arr[x + dx[i]][y + dy[i]] != 'Z'
        && arr[x + dx[i]][y + dy[i]] != 'M')
        {
            sur[i] = arr[x + dx[i]][y + dy[i]];
        }
    }
    
    if(sur[0] != 0 && sur[0] != '.' && sur[0] != '1' && sur[0] != '4' && sur[0] != '-'
    && sur[1] != 0 && sur[1] != '.' && sur[1] != '1' && sur[1] != '2' && sur[1] != '|'
    && sur[2] != 0 && sur[2] != '.' && sur[2] != '2' && sur[2] != '3' && sur[2] != '-'
    && sur[3] != 0 && sur[3] != '.' && sur[3] != '3' && sur[3] != '4' && sur[3] != '|')
    {
        return 2;
    }
    else if(sur[0] != 0 && sur[0] != '.' && sur[0] != '-' && sur[0] != '1' && sur[0] != '4'
    && sur[2] != 0 && sur[2] != '.' && sur[2] != '-' && sur[2] != '2' && sur[2] != '3')
    {
        return 0;
    }
    else if(sur[1] != 0 && sur[1] != '.' && sur[1] != '1' && sur[1] != '2' && sur[1] != '|'
    && sur[3] != 0 && sur[3] != '.' && sur[3] != '3' && sur[3] != '4' && sur[3] != '|')
    {
        return 1;
    }
    else if(sur[0] != 0 && sur[0] != '.' && sur[0] != '1' && sur[0] != '4' && sur[0] != '-'
    && sur[1] != 0 && sur[1] != '.' && sur[1] != '1' && sur[1] != '2' && sur[1] != '|')
    {
        return 3;
    }
    // 0 : 아래, 1 : 오른쪽, 2: 위, 3: 왼쪽
    else if(sur[2] != 0 && sur[2] != '.' && sur[2] != '2' && sur[2] != '3' && sur[2] != '-'
    && sur[1] != 0 && sur[1] != '.' && sur[1] != '1' && sur[1] != '2' && sur[1] != '|')
    {
        return 4;
    }
    else if(sur[3] != 0 && sur[3] != '.' && sur[3] != '3' && sur[3] != '4' && sur[3] != '|'
    && sur[2] != 0 && sur[2] != '.' && sur[2] != '2' && sur[2] != '3' && sur[2] != '-')
    {
        return 5;
    }
    else if(sur[3] != 0 && sur[3] != '.' && sur[3] != '3' && sur[3] != '4' && sur[3] != '|'
    && sur[0] != 0 && sur[0] != '.' && sur[0] != '1' && sur[0] != '4' && sur[0] != '-')
    {
        return 6;
    }
    else return -1;
}