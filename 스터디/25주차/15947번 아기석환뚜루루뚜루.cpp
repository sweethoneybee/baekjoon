#include <iostream>
#include <string>
using namespace std;

const string lyrics[14] = {"baby",
                           "sukhwan",
                           "tururu",
                           "turu",
                           "very",
                           "cute",
                           "tururu",
                           "turu",
                           "in ",
                           "bed",
                           "tururu",
                           "turu",
                           "baby",
                           "sukhwan"};
const string appendLyrics = "ru";
int N;

string lengthToString(const int &);
int main(void)
{
  int repeat, wordIndex, k;
  string answer;
  cin >> N;
  N = N - 1;

  repeat = N / 14;
  wordIndex = N % 14;

  answer = lyrics[wordIndex];
  if (wordIndex == 2 || wordIndex == 3 || wordIndex == 6 || wordIndex == 7 || wordIndex == 10 || wordIndex == 11)
  {
    int wordLength = answer.length() + repeat * 2;
    if (wordLength >= 12)
    {
      answer = "tu+ru*" + lengthToString((wordLength - 2) / 2);
    }
    else
    {
      // 그냥 붙여주기
      for (int i = 0; i < repeat; i++)
      {
        answer.append("ru");
      }
    }
  }

  cout << answer;
  return 0;
}

string lengthToString(const int &length)
{
  string reverseString = "";
  string ret = "";
  int len = length;

  while (len > 0)
  {
    reverseString.push_back(len % 10 + '0');
    len /= 10;
  }

  for (auto i = reverseString.rbegin(); i != reverseString.rend(); i++)
  {
    ret.push_back(*i);
  }

  return ret;
}