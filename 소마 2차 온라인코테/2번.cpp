#include <iostream>
#include <vector>
using namespace std;

typedef struct s
{
    s* parent;
    long long x;
    long long y;
    long long maxX;
    long long minX;
    long long maxY;
    long long minY;
    long long index;
}s;

int N, M;
vector<s> v;

s* findParent(s *p)
{
    if(p->parent == p)
        return p;
    else 
        // 기존 것
        //return findParent(p->parent);
        
        // 개선안 - 탐색하면서 부모 바로 이어주기
        return p = findParent(p->parent);
}

void uni(s* a, s* b)
{
    s* tempA = findParent(a);
    s* tempB = findParent(b);

    if(tempA->index < tempB->index)
    {
        tempB->parent = tempA;
        if(tempA->maxX < tempB->maxX)
        {
            tempA->maxX = tempB->maxX;
        }
        if(tempA->minX > tempB->minX)
        {
            tempA->minX = tempB->minX;
        }
        if(tempA->maxY < tempB->maxY)
        {
            tempA->maxY = tempB->maxY;
        }
        if(tempA->minY > tempB->minY)
        {
            tempA->minY = tempB->minY;
        }
    }
    else
    {
        tempA->parent = tempB;
        if(tempB->maxX < tempA->maxX)
        {
            tempB->maxX = tempA->maxX;
        }
        if(tempB->minX > tempA->minX)
        {
            tempB->minX = tempA->minX;
        }
        if(tempB->maxY < tempA->maxY)
        {
            tempB->maxY = tempA->maxY;
        }
        if(tempB->minY > tempA->minY)
        {
            tempB->minY = tempA->minY;
        }
    }
}
int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        s temp;
        cin >> temp.x;
        cin >> temp.y;
        temp.maxX = temp.x;
        temp.minX = temp.x;
        temp.maxY = temp.y;
        temp.minY = temp.y;
        temp.index = i;
        v.push_back(temp);
    }

    for(int i = 0; i < N; i++)
    {
        v[i].parent = &v[i];
    }

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        uni(&v[a-1], &v[b-1]);
    }

    long long answer = 0;
    for(int i = 0; i < N; i++)
    {
        long long dulae = (v[i].maxX - v[i].minX) * 2 + (v[i].maxY - v[i].minY) * 2;
        if(dulae > answer)
        {
            answer = dulae;
        }
    }

    cout << answer;
    
    system("pause");
    return 0;
}

// 7 5
// 13 13
// 16 20
// 15 8
// 12 20
// 13 15
// 12 11
// 14 20
// 7 2
// 4 2
// 7 3
// 1 4
// 7 6
// 답 32