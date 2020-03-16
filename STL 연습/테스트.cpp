#include <iostream>
#include <vector>

using namespace std;
int count = 0;
void Dfs(vector<int>& numbers, int target, int sum, int index)
{
    count++;
    if(index == numbers.size()-1)
    {
        cout << "sum : " << sum << "\n";
        if(sum == target)
        {
            (*numbers.rbegin())++;
        }
    }
    else
    {
        Dfs(numbers, target, sum + numbers[index], index+1);
        Dfs(numbers, target, sum - numbers[index], index+1);
    }
    
}
int solution(vector<int> numbers, int target)
{
    int answer = 0;
    int index = 0;
    int sum = 0;

    numbers.push_back(answer);
    Dfs(numbers, target, sum, index);
    
    answer = (*numbers.rbegin());
    return answer;
}

int main(void)
{
    vector<int> numbers;
    int target;
    for(int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    
    cin >> target;

    int answer = solution(numbers, target);

    cout << "dfs ȣ�� Ƚ�� : " << count << "\n";
    cout << "���� : " << answer << "\n";
    system("pause");
    return 0;
}