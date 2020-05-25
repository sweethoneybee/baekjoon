#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *r_fp;
FILE *w_fp;
struct TreeNode;
typedef struct TreeNode *SearchTree;
typedef struct TreeNode *Node;

struct TreeNode
{
    int dup_count;
    int element;
    SearchTree left;
    SearchTree right;
};

Node makeNode(int x);
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
    temp->dup_count = 1;
    return temp;
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
        printf("%d is in the tree. count: %d\n", T->element, T->dup_count);
        fprintf(w_fp, "%d is in the tree. count: %d\n", T->element, T->dup_count);
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
        T->dup_count += 1;
    }

    return T;
}
SearchTree Delete(int x, SearchTree T)
{
    Node tmpCell = NULL;

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
        if ( T->dup_count > 1 )
        {
            T->dup_count -= 1;
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
        printf("%d(%d) ", root->element, root->dup_count);
        fprintf(w_fp, "%d(%d) ", root->element, root->dup_count);
        inorder(root->right);
    }
}
