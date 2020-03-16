#include <iostream>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N >> M;

    char **chess = new char*[N];
    for(int i = 0; i < N; i++)
    {
        chess[i] = new char[M];
    }
    for(int i =0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> chess[i][j];
        }
    }

    int **int_chess = new int*[N];
    for(int i = 0; i < N; i++)
    {
        int_chess[i] = new int[M];
    }
    for(int i =0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(chess[i][j] == 'B')
                int_chess[i][j] = -1;
            if(chess[i][j] == 'W')
                int_chess[i][j] = 1;
        }
    }

    int **compareChess = new int*[N];
    for(int i = 0; i < N; i++)
    {
        compareChess[i] = new int[M];
    }
    
    for(int i =0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            compareChess[i][j] = int_chess[i][j];
        }
    }


    int changeCount = 1000000;
    for(int i =0; i < N - 7; i++)
    {
        for(int j=0; j < M - 7; j++)
        {
            for(int k =i; k < i+8; k++)
            {
                for(int l = j; l < j+8; l++)
                {
                    compareChess[k][l] = int_chess[k][l];
                }
            }

            int leftsideColor = 1;
            int count = 0;
            for(int k = i; k < i+8; k++)
            {
                for(int l = j; l < j+8; l++)
                {
                    if(compareChess[k][l] != leftsideColor)
                    {
                        count += 1;
                        compareChess[k][l] = leftsideColor;
                        leftsideColor *= -1;
                        continue;
                    }
                    leftsideColor *= -1;
                }
                leftsideColor *= -1;
            }          

 
            if(count < changeCount)
            {
                changeCount = count;
            }

            for(int k =i; k < i+8; k++)
            {
                for(int l = j; l < j+8; l++)
                {
                    compareChess[k][l] = int_chess[k][l];
                }
            }

            leftsideColor = -1;
            count = 0;
            for(int k = i; k < i+8; k++)
            {
                for(int l = j; l < j+8; l++)
                {
                    if(compareChess[k][l] != leftsideColor)
                    {
                        count += 1;
                        compareChess[k][l] = leftsideColor;
                        leftsideColor *= -1;
                        continue;
                    }
                    leftsideColor *= -1;
                }
                leftsideColor *= -1;
            }
            if(count < changeCount)
            {
                changeCount = count;
            }
        }
    }

    cout << changeCount;
    for(int i = 0; i < N; i++)
    {
        delete[] chess[i];
        delete[] int_chess[i];
        delete[] compareChess[i];
    }
    delete[] chess;
    delete[] int_chess;
    delete[] compareChess;
    cin >> N;


    return 0;
}



