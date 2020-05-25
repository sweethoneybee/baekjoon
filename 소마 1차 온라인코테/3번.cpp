#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int main(void)
{
    cin >> N >> K;

    int *input = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> input[i];
    }

    int sum = 0;
    int *arr = new int[N-1];
    for(int i = 0; i < N - 1; i++)
    {
        arr[i] = input[i+1] - input[i];
        sum += arr[i];
    }
    sort(arr, arr + N-1);
    int index = N-2;

    for(int i = 0; i < K - 1; i++)
    {
        sum -= arr[index];
        index--;
    }

    cout << sum << "\n";

    system("pause");
    delete[] input;
    delete[] arr;
    return 0;
}