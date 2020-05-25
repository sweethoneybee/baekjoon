#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int arr[10][10] = {0};
int N, M;
int win = 0;
queue<pair<int, int>> que;
pair<int, int> goal;
bool chk(int x, int y);
void bfs();

int main(void)
{
    cin >> N >> M;
    string input;
    pair<int, int> red, blue;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        for(int j = 0; j < M; j++)
        {
            arr[i][j] = input[j];
            if(input[j] == 'R')
            {
                red.first = i;
                red.second = j;
            }
            if(input[j] == 'B')
            {
                blue.first = i;
                blue.second = j;
            }
        }
    }
    que.push(red);
    que.push(blue);
    bfs();

    if(win == 1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    
    system("pause");
    return 0;
}

bool chk(int x, int y)
{
    if(x >= 0 && x <= N - 1 && y >= 0 && y <= M) return true;
    else return false;
}

void bfs()
{
    int time = 0;
    int whoFirst = 0;
    while(que.empty() != true)
    {
        if(time == 10)
        {
            break;
        }
        for(int k = 0, size = que.size() / 2; k < size; k++)
        {
            int redX = que.front().first; 
            int redY = que.front().second;
            que.pop();
            int blueX = que.front().first;
            int blueY = que.front().second;
            que.pop();

            for(int i = 0; i < 4; i++)
            {            
                win = whoFirst = 0;
                int nx = dx[i]; int ny = dy[i];
                switch (i)
                {
                case 0:
                    if(redY == blueY)
                    {
                        if(redX > blueX) whoFirst = 1;
                        else whoFirst = 2;
                    }
                    break;
                case 1:
                    if(redX == blueX)
                    {
                        if(redY > blueY) whoFirst = 1;
                        else whoFirst = 2;
                    }
                    break;
                case 2:
                    if(redY == blueY)
                    {
                        if(redX < blueX) whoFirst = 1;
                        else whoFirst = 2;
                    }
                    break;
                case 3:
                    if(redX == blueX)
                    {
                        if(redY < blueY) whoFirst = 1;
                        else whoFirst = 2;
                    }
                    break;
                default:
                    break;
                }

                int moveRedX = redX; int moveRedY = redY;
                int moveBlueX = blueX; int moveBlueY = blueY;

                while(chk(moveRedX + nx, moveRedY + ny) 
                && arr[moveRedX + nx][moveRedY + ny] != '#')
                {
                    moveRedX += nx;
                    moveRedY += ny;
                    if(arr[moveRedX][moveRedY] == 'O')
                    {
                        win = 1;
                        break;
                    }
                }
                while(chk(moveBlueX + nx, moveBlueY + ny) 
                && arr[moveBlueX + nx][moveBlueY + ny] != '#')
                {
                    moveBlueX += nx;
                    moveBlueY += ny;
                    if(arr[moveBlueX][moveBlueY] == 'O')
                    {
                        win = -1;
                        break;
                    }
                }

                if(win == 1) break;
                if(win == -1) continue;

                if(moveRedX == moveBlueX && moveRedY == moveBlueY)
                {
                    if(whoFirst == 1)
                    {
                        moveBlueX -= nx;
                        moveBlueY -= ny;
                    }
                    else if(whoFirst == 2)
                    {
                        moveRedX -= nx;
                        moveRedY -= ny;
                    }
                }
                //cout << "move Red X : " << moveRedX << " move Red Y : " << moveRedY << endl;;
                //cout << "move Blue X : " << moveBlueX << " move Blue Y : " << moveBlueY << endl;
               // cout << "red X : " << redX << " red Y : " << redY << endl;
               // cout << "blue X : " << blueX << " blue Y : " << blueY << endl;

                if((redX != moveRedX || redY != moveRedY) 
                || (blueX != moveBlueX || blueY != moveBlueY))
                {   
                    que.push(make_pair(moveRedX, moveRedY));
                    que.push(make_pair(moveBlueX, moveBlueY));
                }
            }
            if(win == 1) break;
        }
        if(win == 1) break;
        time++;
    }
}

// 8 8
// ########
// #R.#####
// ##..##B#
// ###..###
// ####..##
// #####..#
// ######O#
// ########
