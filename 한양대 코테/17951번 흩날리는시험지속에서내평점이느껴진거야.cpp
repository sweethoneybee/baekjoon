#include <iostream>
using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;

    int* num = new int[N];
    for(int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    int stride = N / K;

    int smallest = 555555555;
    for(int i = 0 ; i < N; i += stride)
    {
        int sum = 0;
        for(int j = i; j < i + stride && j < N; j++)
        {
            sum += num[j];
        }

        if(smallest > sum)
        {
            smallest = sum;
        }
    }

    cout << smallest; 
    system("pause");
    return 0;
}