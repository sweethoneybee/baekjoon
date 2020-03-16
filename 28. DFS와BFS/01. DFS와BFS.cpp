#include <iostream>
#include <queue>
#include <cstdio>
#include <functional>
using namespace std;

class node
{
public:
    node();
    int color; // while : 0, gray : 1, black : 2;
    int index;
    priority_queue< int, vector<int>, greater<int> > adj;

};

node::node()
{
    color = 0;
    index = 0;
}

void visitDFS(node *dfs, int index, queue<int> &answer)
{
    answer.push(index);
    node *me = &dfs[index];
    me->color = 1;

    while(me->adj.empty() != true)
    {
        int adj = me->adj.top();
        me->adj.pop();

        if(dfs[adj].color == 0)
        {
            visitDFS(dfs, adj, answer);
        }
    }

    me->color = 2;
}

int main(void)
{
    int N, M, V;
    cin >> N >> M >> V;

    node bfs[N+1];
    node dfs[N+1];
    for(int i = 1; i <= N; i++)
    {
        bfs[i].index = i;
        dfs[i].index = i;
    }
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        bfs[a].adj.push(b);
        bfs[b].adj.push(a);
        dfs[a].adj.push(b);
        dfs[b].adj.push(a);
    }

    queue<int> answerBFS;
    queue<int> answerDFS;

    queue<int> BFS;
    BFS.push(V);
    bfs[V].color = 1;
    while(BFS.empty() != true)
    {
        node* exam = &bfs[BFS.front()];
        answerBFS.push(BFS.front());
        BFS.pop();

        while(exam->adj.empty() != true)
        {
            node* adj = &bfs[exam->adj.top()];
            exam->adj.pop();
            
            if(adj->color == 0)
            {
                adj->color = 1;
                BFS.push(adj->index);
            }
        }

        exam->color = 2;
    }

    visitDFS(dfs, V, answerDFS);





    while(answerDFS.empty() != true)
    {
        cout << answerDFS.front() << " ";
        answerDFS.pop();
    }
    cout << "\n";
    while(answerBFS.empty() != true)
    {
        cout << answerBFS.front() << " ";
        answerBFS.pop();
    }


    system("pause");
    return 0;
}