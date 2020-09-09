
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
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    int input;
    cin >> input;
    nums.insert(input);
  }
  cin >> L;

  for (auto i = nums.rbegin(); i != nums.rend(); i++)
  {
    if (L == *i)
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
  for (auto i = nums.rbegin(); i != nums.rend(); i++)
  {
    if (*i >= L)
    {
      b = *i;
      break;
    }
  }

  return 0;
}