#include <iostream>
#include <vector>
using namespace std;

bool Chk1(int x, int y, int ax, int ay, int bx, int by);
class cor
{
public:
    int x;
    int y;
    cor(int x, int y) : x(x), y(y)  {}
};

int H, W, N;
vector<cor> sticker;
int answer = 0;
void Dfs(int, int, int);

int main(void)
{
    cin >> H >> W;
    cin >> N;
    for(int n = 0; n < N; n++)
    {
        int x, y;
        cin >> x >> y;
        sticker.push_back(cor(x, y));
    }
    for(int i = 0; i < sticker.size() - 1; i++)
    {
        Dfs(i, i, 1);
    }

    cout << answer;
    system("pause");
    return 0;
}

void Dfs(int start, int end, int cnt)
{
    if(cnt >= 2)
    {
        int temp = 0;
        if(Chk1(H, W, sticker[start].x, sticker[start].y, sticker[end].x, sticker[end].y))
        {
            temp = (sticker[start].x * sticker[start].y) + (sticker[end].x * sticker[end].y);
        }

        
        answer = max(answer, temp);
    }
    else
    {
        for(int i = start+1; i < sticker.size(); i++)
        {
            Dfs(start, i, cnt + 1);
        }
    }
    
}

bool Chk1(int x, int y, int ax, int ay, int bx, int by)
{
    if(x >= ax && y >= ay)
    {
        if(x-ax >= bx && y >= by) return true;
        else if(x - ax >= by && y >= bx) return true;
        else if(y - ax >= bx && x >= by) return true;
        else if(y - ax >= by && x >= bx) return true;
        else return false;
    }
    else return false;
}
