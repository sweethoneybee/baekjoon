#include <iostream>
using namespace std;

int main(void)
{
  int N, i;
  cin >> N;

  for (i = 0; i < N; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << "*";
    }
    cout << "\n";
  }
  for (i = N - 1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}