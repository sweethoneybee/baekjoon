#include <iostream>
#include <queue>
#include <list>

using namespace std;


class node
{
public:
    int color; // white : 0, gray : 1, black : 2
    int distance;
    node *from;
    list<node*> next;

    void inputNode(node* nextNode)
    {
        next.push_back(nextNode);
    }
};

node::node()
{
    color = 0;
    distance = 0;
    from = NULL;
}



int main(void)
{
    int N, M, V;
    cin >> N >> M >> V;
    queue<node*> que;
    node bfs[N+1];
    node dfs[N+1];
    
    for(int i = 0; i < M; i++)
    {   
        int a, b;
        cin >> a >> b;
        bfs[a].inputNode(&bfs[b]);
        bfs[b].inputNode(&bfs[a]);
        dfs[a].inputNode(&dfs[b]);
        dfs[b].inputNode(&dfs[a]);
    }
    
    // bfs start
    que.push(&bfs[V]);
    bfs[V].color = 1;
    while(que.empty() == true)
    {
        node *exam = que.front();
        que.pop();

        for(list<node*>::iterator i = exam->next.begin(); i != exam->next.end(); i++)
        {
            if((*i)->color == 0)
            {
                (*i)->color = 1;
                (*i)->distance = exam->distance + 1;
                (*i)->from = exam;
                que.push((*i));
            }
        }
        exam->color == 2;
    }
    system("pause");
    return 0;
}