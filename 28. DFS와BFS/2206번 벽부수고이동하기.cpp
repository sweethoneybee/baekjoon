#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int N, M;
int numberMap[1000][1000] = {0};
int moveCount[2][1000][1000] = {0};
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
    string s;
    cin >> s;
    for (int j = 0; j < M; j++)
    {
      numberMap[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i < 2; i++)
    fill_n(moveCount[i][0], 1000 * 1000, 2000000);
  nextCoor.push(make_pair(0, 0));
  nextBreakWallCount.push(0);
  moveCount[0][0][0] = 1;
  bfs();

  int temp_answer = moveCount[0][N - 1][M - 1] < moveCount[1][N - 1][M - 1] ? moveCount[0][N - 1][M - 1] : moveCount[1][N - 1][M - 1];
  if (temp_answer != 2000000)
    answer = temp_answer;
  cout << answer;

  return 0;
}

void bfs()
{
  while (nextCoor.empty() != true)
  {
    int x, y, d;

    x = nextCoor.front().first;
    y = nextCoor.front().second;
    d = nextBreakWallCount.front();
    nextCoor.pop();
    nextBreakWallCount.pop();

    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      int breakWallCount = d;
      int isBreak = 0;
      if (!checkCoor(nx, ny))
        continue;
      if (numberMap[nx][ny] == 1 && breakWallCount == 1)
        continue;
      //이부분
      // 작더라도, breakWallCount가 다르다면 갈 수 있어야 함.
      // 1. 벽한개만 부수고 이동하기
      // 2. 벽 아예 안부수고 이동하기

      if (numberMap[nx][ny] == 1)
      {
        breakWallCount = 1;
        isBreak = 1;
      }

      if (moveCount[breakWallCount][nx][ny] <= moveCount[breakWallCount - isBreak][x][y] + 1)
        continue;

      moveCount[breakWallCount][nx][ny] = moveCount[breakWallCount - isBreak][x][y] + 1;
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
