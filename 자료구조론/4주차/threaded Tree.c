#include <stdio.h>
#include <stdlib.h>
// inorder로만 만들 것
typedef struct threaded_tree *tree_ptr;
typedef struct threaded_tree
{
    short int left_thread;
    tree_ptr left_child;
    char data;
    tree_ptr right_child;
    short int right_thread;
}tree;

typedef struct queue
{
    int front;
    int rear;
    int size;
    int capacity;
    tree_ptr *arr;
}queue;
typedef queue* que;

// tree functions
tree_ptr makeEmpty();
tree_ptr makeNode(char data);
void insertNode(tree_ptr node, tree_ptr tree);
void tInorder(tree_ptr tree);
tree_ptr insucc(tree_ptr node);

// que functinos
que createQueue(int size);
void enQ(que q, tree_ptr e);
tree_ptr deQ(que q);
short int emptyQue(que q);
void destroyQue(que q);

FILE* r_fp;
FILE* w_fp;
int main(void)
{
    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    int N;
    fscanf(r_fp, "%d\n", &N);
    char *arr = (char*)malloc(sizeof(char) * N);
    int i = 0;
    for(; i < N; i++)
    {
        fscanf(r_fp, "%c", &arr[i]);
        fseek(r_fp, 1, SEEK_CUR);
    }

    tree_ptr root = makeEmpty();
    for(i = 0; i < N; i++)
    {
        tree_ptr temp = makeNode(arr[i]);
        insertNode(temp, root);
    }

    tInorder(root);
    system("pause");
    return 0;
}

tree_ptr makeEmpty()
{
    tree_ptr temp = (tree_ptr)malloc(sizeof(tree));
    temp->left_child = temp;
    temp->right_child = temp;
    temp->data = '\0';
    temp->left_thread = 0;
    temp->right_thread = 0;

    return temp;
}
tree_ptr makeNode(char data)
{
    tree_ptr temp = (tree_ptr)malloc(sizeof(tree));
    temp->data = data;
    temp->left_thread = 1;
    temp->right_thread = 1;
    temp->left_child = NULL;
    temp->right_child = NULL;

    return temp;
}
void insertNode(tree_ptr node, tree_ptr tree)
{
    if(tree->left_child == tree)
    {
        tree->left_child = node;
        node->left_child = tree;
        node->right_child = tree;
        return;
    }

    que q = createQueue(120); // enough 
    enQ(q, tree->left_child);
    
    tree_ptr temp;
    while(emptyQue(q) != 1)
    {
        temp = deQ(q);

        if(temp->left_thread == 1)
        {
            destroyQue(q);
            node->left_child = temp->left_child;
            node->right_child = temp;

            temp->left_thread = 0;
            temp->left_child = node;
            return;
        }
        if(temp->right_thread == 1)
        {
            destroyQue(q);
            node->left_child = temp;
            node->right_child = temp->right_child;

            temp->right_thread = 0;
            temp->right_child = node;
            return;
        }

        enQ(q, temp->left_child);
        enQ(q, temp->right_child);
    }
}
void tInorder(tree_ptr tree)
{
    tree_ptr temp = tree;
    for(;;)
    {
        temp = insucc(temp);
        if(temp == tree) break;
        printf("%c ", temp->data);
        fprintf(w_fp, "%c ", temp->data);
    }
}

tree_ptr insucc(tree_ptr tree)
{
    tree_ptr temp;
    temp = tree->right_child;
    if(!(tree->right_thread))
    {
        while(!temp->left_thread)
        {
            temp = temp->left_child;
        }
    }
    return temp;
}
que createQueue(int size)
{
    que temp = (que)malloc(sizeof(queue));
    if(temp == NULL)
    {
        printf("error!\n");
    }

    temp->arr = (tree_ptr*)malloc(sizeof(tree_ptr) * size);
    if(temp->arr == NULL)
    {
        printf("error!\n");
    }

    temp->capacity = size;
    temp->size = 0;
    temp->front = 1;
    temp->rear = 0;

    return temp;
}
void enQ(que q, tree_ptr e)
{
    if(q->size == q->capacity)
    {
        fprintf(w_fp, "Full\n");
        printf("Full\n");
        return;
    }

    q->arr[(++q->rear) % q->capacity] = e; 
    ++q->size;
    return;
}
tree_ptr deQ(que q)
{
    if(q->size == 0)
    {
        fprintf(w_fp, "Empty\n");
        printf("Empty\n");
        return 0;
    }

    tree_ptr e = q->arr[(q->front++) % q->capacity];
    --q->size;
    
    return e;
}
short int emptyQue(que q)
{
    if(q->size == 0)
    {
        return 1;
    }
    return 0;
}
void destroyQue(que q)
{
    free (q->arr);
}