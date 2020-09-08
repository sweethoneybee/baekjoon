#include <iostream>
#include <cstdint>
using namespace std;

int32_t N, R, C;
char farm[100][100] = {0};

void plantCarrot(const int &, const int &);
int main(void)
{
  cin >> N >> R >> C;

  int32_t mod_R, mod_C;
  mod_R = R % 2;
  mod_C = C % 2;
  if (mod_R == mod_C)
  {
    plantCarrot(0, 0);
  }
  else
  {
    plantCarrot(0, 1);
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

void plantCarrot(const int &x, const int &y)
{
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= N; j++)
    {
      if (i % 2 == x % 2 && j % 2 == y % 2)
        farm[i][j] = 'v';
      else if (i % 2 == (x + 1) % 2 && j % 2 == (y + 1) % 2)
        farm[i][j] = 'v';
      else
        farm[i][j] = '.';
    }
  }
}