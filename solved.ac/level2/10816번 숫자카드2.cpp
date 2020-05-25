#include <stdio.h>
#include <map>
using namespace std;

int N, M;
map<int, int> cards;

int main(void)
{
    scanf("%d", &N);
    int temp;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        cards[temp]++;
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &temp);
        printf("%d ", cards[temp]);
    }
    
    scanf("%d", &N);
    return 0;
}