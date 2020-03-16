#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    
    int* rank = new int[N];
    int* height = new int[N];
    int* weight = new int[N];

    for(int i =0; i<N; i++)
    {
        cin >> weight[i];
        cin >> height[i];
    }


    for(int i =0; i<N;i++)
    {
        int countRank = 0;

        for(int j=0; j<N; j++)
        {
            bool isTall = 0;
            bool isHeavy = 0;
            if(i==j)
                continue;

            if(weight[j] > weight[i])
                isTall = 1;
            
            if(height[j] > height[i])
                isHeavy = 1;

            if(isTall && isHeavy)
                countRank += 1;          
        }
        rank[i] = countRank + 1;
    }


    for(int i = 0; i<N; i++)
    {
        cout << rank[i] << ' ';
    }

    cin >> N;

    delete[] weight;
    delete[] height;
    delete[] rank;
    return 0;
}