#include <iostream>
#include <vector>
using namespace std;

int K; int count = 0;
vector<pair<int, int>> answer;
void hanoi(int from, int temp, int to, int n, int* arr);
int main(void)
{
    cin >> K;
    int* arr = new int[K];
    fill_n(arr, K, 0);
    arr[0] += K;
    
    hanoi(0, 1, 2, K, arr);
    cout << count << endl;
    for(auto i = answer.begin(); i != answer.end(); i++)
    {
        cout << i->first+1 << " " << i->second+1 << "\n";
    }
    
    system("pause");
    return 0;
}
void hanoi(int from, int temp, int to, int n, int* arr)
{
    if(n <= 1)
    {
        answer.push_back(make_pair(from, to));
        arr[from]--;
        arr[to]++;
        //cout << arr[0] << arr[1] << arr[2] << endl;
        count++;
    }
    else
    {
        hanoi(from, to, temp, n-1, arr);
        arr[from] -= 1; arr[to] += 1;
        answer.push_back(make_pair(from, to));
        //cout << arr[0] << arr[1] << arr[2] << endl;
        count++;
        hanoi(temp, from, to, n-1, arr);
    }
    
}