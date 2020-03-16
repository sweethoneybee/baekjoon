#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    double scores[N] = {0};
    for(int i = 0 ; i< N; i++)
    {
        cin >> scores[i];
    }

    double max = -1;
    for(int i =0; i< N; i++)
    {
        if(scores[i] > max)
        {
            max = scores[i];
        }
    }

    double result = 0;
    for(int i = 0 ; i< N; i++)
    {
        result += scores[i] / max * 100;
    }

 
    result = result / N;

    cout << result;
    
    system("pause");
    return 0;
}