#include <iostream>
#include <string>
#include <queue>
using namespace std;
queue<int> que;
void getInt(queue<int>& que)
{
    string temp = "1 2 3 4 5 10 20 30";
    int start, end;
    start = end = 0;
    int strSize = temp.length();
    while(true)
    {
        end = temp.find(" ", start);
        que.push(stoi(temp.substr(start, end - start)));
        if(end == string::npos)
        {
            break;
        }

        start = end + 1;
        que.pop();
    }
}
int main(void)
{
    getInt(que);
    while(que.empty() != true)
    {
        cout << que.front() << endl;
        que.pop();
    }
    system("pause");
    return 0;
}