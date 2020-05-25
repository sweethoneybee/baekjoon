#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE* r_fp;
FILE* w_fp;
struct TreeNode;
typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Node;

struct TreeNode
{
    int element;
    SearchTree left;
    SearchTree right;
    SearchTree *list;
    int listIdx;
};
Node makeNode(int x);
SearchTree LinkDupKey(int x, SearchTree T);
Node FindMin(SearchTree T);
// Find, Insert, Delete
Node Find(int x, SearchTree T);
SearchTree Insert(int x, SearchTree T);
SearchTree Delete(int x, SearchTree T);
void inorder(Node root);

int main(void)
{

    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    char oper[3];
    int value;
    Node root = NULL;
    while ( fscanf(r_fp, "%s", oper) != EOF )
    {
        // print tree
        if ( oper[0] == 'p' )
        {
            inorder(root);
            printf("\n");
            fprintf(w_fp, "\n");
            continue;
        }

        // operation
        fscanf(r_fp, "%d\n", &value);
        if ( oper[0] == 'i' )
        {
            root = Insert(value, root);
        }
        if ( oper[0] == 'd' )
        {
            Delete(value, root);
        }
        if ( oper[0] == 'f' )
        {
            Find(value, root);
        }
    }

//    system("pause");
    return 0;
}

Node makeNode(int x)
{
    Node temp = (Node)malloc(sizeof(struct TreeNode));
    temp->element = x;
    temp->left = NULL;
    temp->right = NULL;
    temp->list = NULL;
    temp->listIdx = 0;

    return temp;
}
SearchTree LinkDupKey(int x, SearchTree T)
{
    if ( T->list == NULL )
    {
        T->list = (SearchTree *)malloc(sizeof(SearchTree) * 100);
        T->listIdx = 0;
    }

    if ( T->listIdx < 100 )
    {
        T->list[T->listIdx++] = makeNode(x);
        T->list[T->listIdx]->listIdx = T->listIdx;
    }
    else
    {
        printf("Duplicate Keys are full!\n");
        fprintf(w_fp, "Duplicate Keys are full!\n");
    }

    return T;
}
Node FindMin(SearchTree T)
{
    if ( T == NULL )
        return NULL;
    else if ( T->left == NULL )
        return T;
    else
        return FindMin(T->left);
}


// Find, Insert, Delete
Node Find(int x, SearchTree T)
{
    if ( T == NULL )
    {
        printf("%d is not in the tree.\n", x);
        fprintf(w_fp, "%d is not in the tree.\n", x);
        return NULL;
    }
    if ( x < T->element )
    {
        return Find(x, T->left);
    }
    else if ( x > T->element )
    {
        return Find(x, T->right);
    }
    else
    {
        printf("%d is in the tree. count: %d\n", x, T->listIdx + 1);
        fprintf(w_fp, "%d is in the tree. count: %d\n", x, T->listIdx + 1);
        return T;
    }
}
SearchTree Insert(int x, SearchTree T)
{
    if ( T == NULL )
    {
        T = makeNode(x);
    }
    else if ( x < T->element )
    {
        T->left = Insert(x, T->left);
    }
    else if ( x > T->element )
    {
        T->right = Insert(x, T->right);
    }
    else
    {
        T = LinkDupKey(x, T);
    }

    return T;
}
SearchTree Delete(int x, SearchTree T)
{
    Node tmpCell;

    if ( T == NULL )
    {
        printf("Deletion failed. %d does not exist.\n", x);
        fprintf(w_fp, "Deletion failed. %d does not exist.\n", x);
    }
    else if ( x < T->element )
    {
        T->left = Delete(x, T->left);
    }
    else if ( x > T->element )
    {
        T->right = Delete(x, T->right);
    }
    else // found key to be deleted
    {
        if ( T->listIdx > 0 )
        {
            free(T->list[--T->listIdx]);
            if ( T->listIdx == 0 ) free(T->list);
        }
        else
        {
            if ( T->left && T->right ) // 2 child
            {
                tmpCell = FindMin(T->right);
                T->element = tmpCell->element;
                T->right = Delete(T->element, T->right);
            }
            else
            {
                tmpCell = T;
                if ( T->left == NULL )
                    T = T->right;
                else if ( T->right == NULL )
                    T = T->left;
                free(tmpCell);
            }
        }
    }

    return T;
}

void inorder(Node root)
{
    if ( root != NULL )
    {
        inorder(root->left);
        printf("%d(%d) ", root->element, root->listIdx + 1);
        fprintf(w_fp, "%d(%d) ", root->element, root->listIdx + 1);
        inorder(root->right);
    }
}