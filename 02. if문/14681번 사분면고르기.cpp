#include <iostream>
using namespace std;

int main(void)
{
  int x, y, answer;
  cin >> x >> y;

  if (x > 0)
  {
    if (y > 0)
    {
      answer = 1;
    }
    else
    {
      answer = 4;
    }
  }
  else
  {
    if (y > 0)
    {
      answer = 2;
    }
    else
    {
      answer = 3;
    }
  }

  cout << answer;
  return 0;
}