#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
    int left;
    int right;    
}node;
vector<int> pre;
vector<int> in;
vector<int> post;
node tree[26];
int N;

void Pre(int index);
void In(int index);
void Post(int index);

int main(void)
{
    cin >> N;
    char a, b, c;
    for(int i = 0; i < N; i++)
    {
        cin >> a >> b >> c;
        int parent = a - 'A';
        int left = b - 'A';
        int right = c - 'A';
        
        tree[parent].left = -1;
        tree[parent].right = -1;
        
        if(b >= 'A' && b <= 'Z')
        {
            tree[parent].left = left;
        }    
        if(c >= 'A' && c <= 'Z')
        {
            tree[parent].right = right;
        }
    }

    Pre(0);
    In(0);
    Post(0);

    for(int i = 0; i < N; i++)
    {
        cout << char(pre[i]);
    }
    cout << "\n";
    for(int i = 0; i < N; i++)
    {
        cout << char(in[i]);
    }
    cout << "\n";
    for(int i = 0; i < N; i++)
    {
        cout << char(post[i]);
    }

    system("pause");
    return 0;
}

void In(int index)
{
    if(index != -1)
    {
        In(tree[index].left);
        in.push_back(index + 'A');
        In(tree[index].right);
    }
}
void Pre(int index)
{
    if(index != -1)
    {
        pre.push_back(index + 'A');
        Pre(tree[index].left);
        Pre(tree[index].right);
    }
}
void Post(int index)
{
    if(index != -1)
    {
        Post(tree[index].left);
        Post(tree[index].right);
        post.push_back(index + 'A');
    }
}