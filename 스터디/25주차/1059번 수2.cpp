
// 주어진 L개의 수와 N이 같으면 답은 0
// 주어진 L개의 수 중 N과 같은 것이 없다면
// N이 포함된 가장 긴 구간을 구한다. ex) N = 5 면 [2, 8]
// 구간의 길이가 1이하면 답은 0.
// ex) N = 4이고 [4,8]
// 해당 구간을 [a, b]라 하였을 때
// a나 b가 N과 같은 경우
//
// for (int i = a; i <= N; i++)
// {
//   if(i == N)
//   {
//     // b - N 개 더하기
//   }
//   else
//   {
//     // 해당 구간에서 b - N + 1 개 더하기
//   }
// }

#include <iostream>
#include <set>
using namespace std;

set<int> nums;
int L, N, a, b;

int main(void)
{
  int answer = 0;
  bool hasLuckySet = true;
  cin >> L;
  for (int i = 0; i < L; i++)
  {
    int input;
    cin >> input;
    nums.insert(input);
  }
  cin >> N;

  for (auto i = nums.rbegin(); i != nums.rend(); i++)
  {
    if (N == *i)
    {
      hasLuckySet = false;
      break;
    }
  }
  if (hasLuckySet == false)
  {
    cout << answer;
    return 0;
  }

  a = -1;
  b = 1001;
  for (auto i = nums.begin(); i != nums.end(); i++)
  {
    if (*i > N)
    {
      b = *i;
      break;
    }
  }
  for (auto i = nums.rbegin(); i != nums.rend(); i++)
  {
    if (*i < N)
    {
      a = *i;
      break;
    }
  }

  // 구간 사이에 있는 경우
  if (b != 1001 && a != -1)
  {
    for (int i = a + 1; i <= N; i++)
    {
      answer += (b - N);
      if (i == N)
        answer -= 1;
    }
  }
  // N보다 큰 값이 없는 경우
  else if (b == 1001 && a != -1)
  {
    b = 1000;
    for (int i = a + 1; i <= N; i++)
    {
      answer += (b - N + 1);
      if (i == N)
        answer -= 1;
    }
  }
  // N보다 작은 값이 없는 경우
  else if (b != 1001 && a == -1)
  {
    a = 0;
    for (int i = a + 1; i <= N; i++)
    {
      answer += (b - N);
      if (i == N)
        answer -= 1;
    }
  }

  cout << answer;
  return 0;
}