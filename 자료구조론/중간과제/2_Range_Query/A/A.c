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
};
int count = 0;

Node makeNode(int x);
void RangeSearch(SearchTree T, int k1, int k2);
Node FindMin(SearchTree T);
Node Find(int x, SearchTree T);
SearchTree Insert(int x, SearchTree T);
SearchTree Delete(int x, SearchTree T);
void inorder(Node root);

int main(void)
{

    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    char oper[3];
    int value1;
    int value2;
    Node root = NULL;

    while ( fscanf(r_fp, "%s", oper) != EOF )
    {
        // print tree
        if ( oper[0] == 's' )
        {
            count = 0;
            fscanf(r_fp, "%d", &value1);
            fscanf(r_fp, "%d\n", &value2);
            RangeSearch(root, value1, value2);
            printf("between %d and %d: key value count = %d\n", value1, value2, count);
            fprintf(w_fp, "between %d and %d: key value count = %d\n", value1, value2, count);
            continue;
        }
        if ( oper[0] == 'p')
        {
            inorder(root);
            printf("\n");
            fprintf(w_fp, "\n");
            continue;
        }
        // operation
        fscanf(r_fp, "%d\n", &value1);
        if ( oper[0] == 'i' )
        {
            root = Insert(value1, root);
        }
        if ( oper[0] == 'd' )
        {
            Delete(value1, root);
        }
        if ( oper[0] == 'f' )
        {
            Find(value1, root);
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

    return temp;
}

void RangeSearch(SearchTree T, int k1, int k2)
{
    if(T!= NULL)
    {
        if(T->element > k1)
            RangeSearch(T->left, k1, k2);
        
        if(T->element >= k1 && T->element <= k2)
        {
            count++;
        }

        if(T->element < k2)
            RangeSearch(T->right, k1, k2);
    }
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
        printf("%d is in the tree.\n", T->element);
        fprintf(w_fp, "%d is in the tree.", T->element);
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

    return T;
}

void inorder(Node root)
{
    if ( root != NULL )
    {
        inorder(root->left);
        printf("%d ", root->element);
        fprintf(w_fp, "%d ", root->element);
        inorder(root->right);
    }
}
