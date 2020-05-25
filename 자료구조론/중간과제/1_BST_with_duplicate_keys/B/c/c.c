#include <stdio.h>
#include <stdlib.h>
FILE* r_fp;
FILE* w_fp;

typedef struct Node* Position;
typedef struct Node* NodePtr;
typedef struct Node
{
    int value;
    NodePtr left, right;
    int height;
}Node;

void printInorder(NodePtr root);
void inorder(NodePtr root);

//AVL fucntions
int height(Position P);
Position singleRotateWithLeft(Position K2);
Position singleRotateWithRight(Position K2);
Position doubleRotateWithLeft(Position K3);
Position doubleRotateWithRight(Position K3);
NodePtr FindMin(NodePtr T);
int FindBalnce(NodePtr T);

NodePtr Insert(int x, NodePtr T);
NodePtr Find(int x, NodePtr T);
NodePtr Delete(int x, NodePtr T);
int MAX(int x, int y)
{
    if(x > y) return x;
    else return y;
}
int main(void)
{
    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    char oper[3];
    int value;
    NodePtr root = NULL;
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
            root = Delete(value, root);
        }
        if ( oper[0] == 'f' )
        {
            Find(value, root);
        }
    }
    fclose(r_fp);
    fclose(w_fp);
//    system("pause");
    return 0;
}

void printInorder(NodePtr root)
{
    inorder(root);
    printf("\n");
    fprintf(w_fp, "\n");
}
void inorder(NodePtr root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        fprintf(w_fp, "%d ", root->value);
        inorder(root->right);
    }
}

int height(Position P)
{
    if ( P == NULL )
    {
        return -1;
    }
    return P->height;
}
NodePtr Insert(int X, NodePtr T)
{
    if(T == NULL)
    {
        T = (NodePtr)malloc(sizeof(Node));
        
        T->value = X; 
        T->height = 0;
        T->left = T->right = NULL;
    }
    else if(T->value == X)
    {
        T->left = Insert(X, T->left);
        if(height(T->left) - height(T->right) == 2)
        {
            if(T->left->value >= X) // going left
            {
                T = singleRotateWithLeft(T);
            }
            else
            {
                T = doubleRotateWithLeft(T);
            }
        }
    }
    else if(T->value > X)
    {
        T->left = Insert(X, T->left);
        if(height(T->left) - height(T->right) == 2)
        {
            if(T->left->value > X) // going left
            {
                T = singleRotateWithLeft(T);
            }
            else
            {
                T = doubleRotateWithLeft(T);
            }
        }
    }
    else if(T->value < X)
    {
        T->right = Insert(X, T->right);
        if(height(T->right) - height(T->left) == 2)
        {
            if(T->right->value < X) // going right
            {
                T = singleRotateWithRight(T);
            }
            else
            {
                T = doubleRotateWithRight(T);
            }
        }
    }
    T->height = MAX(height(T->left), height(T->right)) + 1;
    return T;
}
Position singleRotateWithLeft(Position K2)
{
    Position K1;

    K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;

    K2->height = MAX(height(K2->left) ,height(K2->right)) + 1;
    K1->height = MAX(height(K1->left), height(K2)) + 1;

    return K1;
}
Position singleRotateWithRight(Position K2)
{
    Position K1;

    K1 = K2->right;
    K2->right = K1->left;
    K1->left = K2;

    K2->height = MAX(height(K2->left), height(K2->right)) + 1;
    K1->height = MAX(height(K1->right), height(K2)) + 1;

    return K1;
}
Position doubleRotateWithLeft(Position K3)
{
    // rotate between K1 and K2
    K3->left = singleRotateWithRight(K3->left);

    // rotate between K3 and K2
    return singleRotateWithLeft(K3);
}
Position doubleRotateWithRight(Position K3)
{
    // rotate between K1 and K2
    K3->right = singleRotateWithLeft(K3->right);

    // rotate between K3 and K2
    return singleRotateWithRight(K3);
}

NodePtr Find(int x, NodePtr T)
{
    if ( T == NULL )
    {
        printf("%d is not in the tree.\n", x);
        fprintf(w_fp, "%d is not in the tree.\n", x);
        return NULL;
    }

    if ( x < T->value )
    {
        return Find(x, T->left);
    }
    else if ( x > T->value )
    {
        return Find(x, T->right);
    }
    else
    {
        printf("%d is in the tree.\n", x);
        fprintf(w_fp, "%d is in the tree.\n", x);
        return T;
    }
}

NodePtr Delete(int x, NodePtr T)
{
    NodePtr tmpCell;

    if ( T == NULL )
    {
        printf("Deletion failed. %d does not exist.\n", x);
        fprintf(w_fp, "Deletion failed. %d does not exist.\n", x);
    }
    else if ( x < T->value )
    {
        T->left = Delete(x, T->left);
    }
    else if ( x > T->value )
    {
        T->right = Delete(x, T->right);
    }
    else // found key to be deleted
    {
        if ( T->left && T->right ) // 2 child
        {
            tmpCell = FindMin(T->right);
            T->value = tmpCell->value;
            T->right = Delete(T->value, T->right);
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

    if(T == NULL)
        return T;

    T->height = MAX(height(T->left), height(T->right)) + 1;
    int balance = FindBalnce(T);
    if(balance > 1 && FindBalnce(T->right) >= 0)
        return singleRotateWithRight(T);
    if(balance > 1 && FindBalnce(T->right) < 0)
        return doubleRotateWithRight(T);
    if(balance < -1 && FindBalnce(T->left) <= 0)
        return singleRotateWithLeft(T);
    if(balance < -1 && FindBalnce(T->left) > 0)
        return doubleRotateWithLeft(T);
    
    return T;
}

NodePtr FindMin(NodePtr T)
{
    if ( T == NULL )
        return NULL;
    else if ( T->left == NULL )
        return T;
    else
        return FindMin(T->left);
}

int FindBalnce(NodePtr T)
{
    return height(T->right) - height(T->left);
}