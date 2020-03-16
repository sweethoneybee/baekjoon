#include <iostream>
#include <queue>
using namespace std;

// 변수선언
int T, h, w;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<vector<int>> prison;
pair<int, int> s1;
pair<int, int> s2;
int minimum = 100000000; 
int count1=0;
int count2=0;
// 큐선언
//priority_queue<int, vector<int>, greater<int>> pq;
// 함수선언
void Dfs(vector<vector<int>>& prison, int x, int y, int count);
void newDfs(vector<vector<int>>& prison, int x, int y, int count);

bool Chk(int, int);

int main(void)
{
    cin >> T;

    for(int t = 0; t < T; t++)
    {   
        count1= 0;
        count2=0;
        minimum = 100000000;
        cin >> h >> w;
        bool chk = 0;
        for(int i = 0; i < h; i++)
        {
            string input;
            cin >> input;
            vector<int> temp;
            for(int j = 0; j < w; j++)
            {
                temp.push_back(input[j]);

                if(input[j] == '#') temp[j] = -1;
                if(input[j] == '*') temp[j] = -2;
                if(input[j] == '.') temp[j] = -3;
                if(input[j] == '$')
                {
                    temp[j] = -4;
                    if(chk == 0)
                    {
                        s1 = make_pair(i, j);
                        chk = 1;
                    }
                    else
                    {
                        s2 = make_pair(i, j);
                    }
                    
                }
            }
            prison.push_back(temp);

        }

        int count = 0;
        Dfs(prison, s1.first, s1.second, count);

        cout << minimum << "\n";

        cout<< "count1 : " << count1 << "\n";
        cout << "count2 : " << count2 << "\n";
        prison.clear();
    }

    

    system("pause");
    return 0;
}

bool Chk(int x, int y)
{
    if(x >= 0 && x <= h-1 && y >= 0 && y <= w-1) return true;
    else return false;
}

void Dfs(vector<vector<int>>& prison, int x, int y, int count)
{
    count1++;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(Chk(nx, ny))
        {
            if(prison[nx][ny] == -1)
            {
                int temp = prison[x][y];
                prison[x][y] = -5;
                Dfs(prison, nx, ny, count+1);
                prison[x][y] = temp;
            }

            else if(prison[nx][ny] == -3)
            {
                int temp = prison[x][y];
                prison[x][y] = -5;
                Dfs(prison, nx, ny, count);
                prison[x][y] = temp;
            }

            else if(prison[nx][ny] == -4)
            {
                int temp = prison[x][y];
                prison[x][y] = -5;
                newDfs(prison, nx, ny, count);
                prison[x][y] = temp;
            }
        }
        else if(!Chk(nx, ny))
        {
            if(prison[s2.first][s2.second] == -4)
            {
                int temp = prison[s2.first][s2.second];
                prison[s2.first][s2.second] = -6;
                newDfs(prison, s2.first, s2.second, count);
                prison[s2.first][s2.second] = temp;
            }
            else
            {
                if(minimum > count) minimum = count;
            }
            
        }
    }
}

void newDfs(vector<vector<int>>& prison, int x, int y, int count)
{
    count2++;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(Chk(nx, ny))
        {
            if(prison[nx][ny] == -1)
            {
                int temp = prison[x][y];
                prison[x][y] = -6;
                newDfs(prison, nx, ny, count+1);
                prison[x][y] = temp;
            }

            else if(prison[nx][ny] == -3)
            {
                int temp = prison[x][y];
                prison[x][y] = -6;
                newDfs(prison, nx, ny, count);
                prison[x][y] = temp;
            }

            else if(prison[nx][ny] == -5)
            {
                int temp = prison[x][y];
                prison[x][y] = -6;
                newDfs(prison, nx, ny, count);
                prison[x][y] = temp;
            }
        }
        
        else if(!Chk(nx, ny))
        {
            if(minimum > count) minimum = count;
        }
    }
}
