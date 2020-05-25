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
    int sub_count;
    int element;
    SearchTree left;
    SearchTree right;
};
Node makeNode(int x);
Node FindMin(SearchTree T);
Node FindMax(SearchTree T);
Node Find(int x, SearchTree T);
SearchTree Insert(int x, SearchTree T);
SearchTree Delete(int x, SearchTree T);
void inorder(Node root);
// range
int RangeSearch(SearchTree T, int k1, int k2);
SearchTree findMid(int k1, int k2, SearchTree T);
int findLeft(int x, int k1, SearchTree T);
int findRight(int x, int k2, SearchTree T);

int main(void)
{

    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    char oper[3];
    int value1, value2, count;
    count = 0;
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
        if ( oper[0] == 'i' )
        {
            fscanf(r_fp, "%d\n", &value1);
            root = Insert(value1, root);
        }
        if ( oper[0] == 'd' )
        {
            fscanf(r_fp, "%d\n", &value1);
            Delete(value1, root);
        }
        if ( oper[0] == 'f' )
        {
            fscanf(r_fp, "%d\n", &value1);
            Find(value1, root);
        }
        if ( oper[0] == 's' )
        {
            fscanf(r_fp, "%d\n", &value1);
            fscanf(r_fp, "%d\n", &value2);
            count = RangeSearch(root, value1, value2);
            printf("between %d and %d : key value count = %d.\n", value1, value2, count);
            fprintf(w_fp, "between %d and %d : key value count = %d.\n", value1, value2, count);
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
    temp->sub_count = 1;
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
Node FindMax(SearchTree T)
{
    if ( T == NULL )
        return NULL;
    else if ( T->right == NULL )
        return T;
    else
        return FindMax(T->right);
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
        printf("%d is in the tree. count: %d\n", T->element, T->sub_count);
        fprintf(w_fp, "%d is in the tree. count: %d\n", T->element, T->sub_count);
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
        T->sub_count += 1;
        T->left = Insert(x, T->left);
    }
    else if ( x > T->element )
    {
        T->sub_count += 1;
        T->right = Insert(x, T->right);
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
        T->sub_count -= 1;
        T->left = Delete(x, T->left);
    }
    else if ( x > T->element )
    {
        T->sub_count -= 1;
        T->right = Delete(x, T->right);
    }
    else // found key to be deleted
    {
        if ( T->left != NULL && T->left->element == x )
        {
            // promised that duplicated key being left
            T->left = Delete(x, T->left);
        }
        else
        {
            if ( T->left && T->right ) // 2 child
            {
                tmpCell = FindMin(T->right);
                T->element = tmpCell->element;
                T->sub_count -= 1;
                T->right = Delete(T->element, T->right);
            }
            else
            {
                tmpCell = T;
                T->sub_count -= 1;
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
        printf("%d(%d) ", root->element, root->sub_count);
        fprintf(w_fp, "%d(%d) ", root->element, root->sub_count);
        inorder(root->right);
    }
}

int RangeSearch(SearchTree T, int k1, int k2)
{
    int count = 0;
    SearchTree mid;
    mid = findMid(k1, k2, T);
    if ( mid == NULL ) return count;

    int midCount, leftCount, rightCount;
    midCount = 1;
    leftCount = findLeft(0, k1, mid->left);
    rightCount = findRight(0, k2, mid->right);

    count = midCount + leftCount + rightCount;


    return count;
}

SearchTree findMid(int k1, int k2, SearchTree T)
{
    if ( T == NULL )
        return NULL;
    else if ( T->element >= k1 && T->element <= k2 )
        return T;
    else if ( T->element > k1 )
    {
        return findMid(k1, k2, T->left);
    }
    //else if(T->element > k2)
    else
    {
        return findMid(k1, k2, T->right);
    }
}
int findLeft(int x, int k1, SearchTree T)
{
    if ( T == NULL )
        return x;
    else if ( T->element > k1 )
    {
        if ( T->left == NULL )
            return x + T->sub_count;
        return findLeft(x + (T->sub_count - T->left->sub_count), k1, T->left);
    }
    else if(T->element < k1 )
    {
        if ( T->right == NULL )
            return x;
        return findLeft(x, k1, T->right);
    }
    else
    {
        if ( T->left == NULL )
            return x + T->sub_count;
        return x + (T->sub_count - T->left->sub_count);
    }
}

int findRight(int x, int k2, SearchTree T)
{
    if ( T == NULL )
        return x;
    else if ( T->element < k2 )
    {
        if ( T->right == NULL )
            return x + T->sub_count;
        return findRight(x + (T->sub_count - T->right->sub_count), k2, T->right);
    }
    else if(T->element > k2 )
    {
        if ( T->left == NULL )
            return x;
        return findRight(x, k2, T->left);
    }
    else
    {
        if ( T->right == NULL )
            return x + T->sub_count;
        return x + (T->sub_count - T->right->sub_count);
    }
}