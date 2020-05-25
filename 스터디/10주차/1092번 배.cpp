#include <iostream>
#include <algorithm>
using namespace std;

int cranes[50] = {0};
int c_count[50] = {0};
int c_index[50] = {0};
int boxes[10000] = {0};
int main(void)
{
    int N, M, crane_max, box_max;
    crane_max = -1;
    box_max = -1;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> cranes[i];
        if(crane_max < cranes[i]) crane_max = cranes[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> boxes[i];
        if(box_max < boxes[i]) box_max = boxes[i];
    }

    if(crane_max < box_max)
    {
        cout << -1;
        system("pause");
        return 0;
    }

    sort(cranes, cranes + N, greater<int>());
    sort(boxes, boxes + M, greater<int>());

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(boxes[j] <= cranes[i])
            {
                c_index[i] = j;
                break;
            }
            else
            {
                c_index[i] = M + 1;
            }
            
        }
    }

    int count = 0;
    int boxCount = M;
    while(boxCount > 0)
    {
        for(int i = 0; i < N && boxCount > 0; i++)
        {
            if(c_index[i] < M)
            {
                for(int j = c_index[i]; j < M; j++)
                {
                    if(boxes[j] != 0)
                    {
                        boxCount--;
                        boxes[j] = 0;
                        c_index[i] = j + 1;
                        c_count[i]++;
                        if(c_count[i] > count)
                        {
                            count = c_count[i];
                        }
                        break;
                    }
                }
            }
        }
    }

    cout << count;
    system("pause");
    return 0;
}