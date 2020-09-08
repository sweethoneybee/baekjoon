#include <iostream>
#include <cstdint>
using namespace std;

int32_t N, R, C;
char farm[100][100] = {0};

int main(void)
{
  cin >> N >> R >> C;

  int32_t mod_R, mod_C;
  mod_R = R % 2;
  mod_C = C % 2;
  if (mod_R == mod_C)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        if (i % 2 == 0 && j % 2 == 0)
          farm[i][j] = 'v';
        else if (i % 2 == 1 && j % 2 == 1)
          farm[i][j] = 'v';
        else
          farm[i][j] = '.';
      }
    }
  }
  else
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        if (i % 2 == 0 && j % 2 == 1)
        {
          farm[i][j] = 'v';
        }
        else if (i % 2 == 1 && j % 2 == 0)
          farm[i][j] = 'v';
        else
          farm[i][j] = '.';
      }
    }
  }

  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      cout << farm[i][j];
    }
    cout << "\n";
  }
  return 0;
}