#include <iostream>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;
    
    int* cards = new int[500];
    for(int i = 0; i < N; i++)
    {
        cin >> cards[i];
    }

    int a, b, c, blackjack;

    blackjack = -1;
    for(int i =0; i<N-2; i++)
    {
        a = cards[i];
        for(int j = i+1; j<N-1; j++)
        {
            b = cards[j];
            for(int k = j+1; k < N; k++)
            {
                c = cards[k];
                
                if(a+b+c > blackjack && a+b+c <= M)
                {
                    blackjack = a+b+c;
                }

                if(blackjack == M)
                {
                    break;
                }
                continue;
            }
            if(blackjack == M)
            {
                break;
            }
        }   
        if(blackjack == M)     
        {
            break;
        }
    }
    
    cout << blackjack;
    delete[] cards;
    //cin >> a;
    return 0;
}