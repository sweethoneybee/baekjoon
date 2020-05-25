#include <iostream>
#include <vector>
using namespace std;

int N;
int num1[51] = {0};
int num2[51] = {0};
bool visited[51] = {0};
int main(void)
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        num1[temp] = 1;
        num2[i+1] = temp;
    }

    for(int i = 1; i <= 50; i++)
    {
        if(num1[i] == 1)
        {
            visited[num2[i]] = 1;
        }
    }
    for(int i = 1; i <= 50; i++)
    {
        if(num1[i] == 1 && visited[i] == 0)
        {
            visited[num2[i]] = 0;
        }
    }

    vector<int> answer;
    for(int i = 1; i <= 50; i++)
    {
        if(visited[i] == 1)
        {
            answer.push_back(i);
        }
    }

    cout << answer.size() << endl;
    for(auto &n : answer)
    {
        cout << n << endl;
    }
    system("pause");
    return 0;
}