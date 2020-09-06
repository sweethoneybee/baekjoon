#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int N, M;
int numberMap[1000][1000] = {0};
int moveCount[1000][1000] = {0};
int answer = -1;
queue<pair<int, int>> nextCoor;
queue<int> nextBreakWallCount;

void bfs();
bool checkCoor(int x, int y);
int main(void)
{
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> numberMap[i][j];
    }
  }
  fill_n(moveCount[0], 1000 * 1000, 1000000);
  nextCoor.push(make_pair(0, 0));
  nextBreakWallCount.push(0);
  moveCount[0][0] = 0;
  bfs();

  if (numberMap[N - 1][M - 1] != 0)
    answer = numberMap[N - 1][M - 1];

  cout << answer;
  return 0;
}

void bfs()
{
  while (nextCoor.empty() != true)
  {
    int x, y, breakWallCount;

    x = nextCoor.front().first;
    y = nextCoor.front().second;
    breakWallCount = nextBreakWallCount.front();
    nextCoor.pop();
    nextBreakWallCount.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (!checkCoor(nx, ny))
        continue;
      if (numberMap[nx][ny] == 1 && breakWallCount == 1)
        continue;
      //이부분
      // 작더라도, breakWallCount가 다르다면 갈 수 있어야 함.
      if (moveCount[nx][ny] < moveCount[x][y] + 1)
        continue;

      moveCount[nx][ny] = moveCount[x][y] + 1;
      if (numberMap[nx][ny] == 1)
        breakWallCount = 1;
      nextCoor.push(make_pair(nx, ny));
      nextBreakWallCount.push(breakWallCount);
    }
  }
}

bool checkCoor(int x, int y)
{
  if (x < 0 || x >= N || y < 0 || y >= M)
    return false;
  return true;
}
