#include <iostream>
#include <vector>
using namespace std;

int T, N, answer;
typedef struct node
{
    node* parent;
    int x;
    int y;
    int r;
}node;
vector<node*> vec;

node* find(node* n);
void connect(node* a, node* b);
int dis(int x1, int y1, int x2, int y2);
int main(void)
{
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        vec.clear();
        answer = 0; 
        cin >> N;
        for(int i = 0; i < N; ++i)
        {
            int x, y, r;
            cin >> x >> y >> r;
            node *temp = new node;
            temp->x = x;
            temp->y = y;
            temp->r = r;
            temp->parent = temp;
            vec.push_back(temp);
        }

        for(int i = 0; i < N; ++i)
        {
            for(int j = i + 1; j < N; ++j)
            {
                int d = dis(vec[i]->x, vec[i]->y, vec[j]->x, vec[j]->y);
                int r = (vec[i]->r + vec[j]->r)*(vec[i]->r + vec[j]->r);

                if(d <= r)
                {
                    connect(vec[i], vec[j]);   
                }
            }
        }

        for(int i = 0; i < N; ++i)
        {
            if(vec[i]->parent == vec[i])
                ++answer;
        }

        cout << answer << "\n";
    }
    system("pause");
    return 0;
}

int dis(int x1, int y1, int x2, int y2)
{
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
node* find(node* n)
{
    if(n->parent == n)
        return n;
    
    return find(n->parent);
}
void connect(node* a, node* b)
{
    node* x = find(a);
    node* y = find(b);

    if(x == y) return;
    y->parent = x;
    return;
}