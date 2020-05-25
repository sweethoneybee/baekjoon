#include <iostream>
using namespace std;

int n, m;
int answer = 0;
int arr[10] = {0};
void per(int index, int cnt);
int main(void)
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        arr[temp] = 1;
    }

    per(0, 0);

    cout << answer;
    system("pause");
    return 0;
}

void per(int index, int cnt)
{
    if(index == n)
    {
        if(cnt == m)
            answer++;
    }
    else
    {
        for(int i = 0; i <= 9; i++)
        {
            if(arr[i] == 1)
            {
                arr[i] = 0;
                per(index + 1, cnt + 1);
                arr[i] = 1;
                continue;
            }
            per(index + 1, cnt);
        }
    }
}