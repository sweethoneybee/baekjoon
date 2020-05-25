#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define order 3
FILE *r_fp;
FILE *w_fp;

typedef struct B_node *B_tree;
struct B_node
{
    int n_keys;
    int leaf;
    B_tree child[order + 1];
    int key[order];
};

int searchIndex(int *key, int n_keys, int x);
B_tree makeNode(int x);
B_tree createNode(void);
B_tree internalInsert(B_tree T, int x, int *mid);
B_tree Insert(int x, B_tree T);
void inorder(B_tree root);

int main(void)
{

    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    int count = 0;
    char oper[3];
    int value;
    B_tree root = createNode();
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
    }

       system("pause");
    return 0;
}

int searchIndex(int *key, int n_keys, int x)
{
    int temp = 0;
    if ( n_keys == 0 )
        temp = 0;
    else if ( n_keys == 1 )
    {
        if ( x < key[0] )
            temp = 0;
        else
            temp = 1;
    }
    else
    {
        if ( x < key[0] )
            temp = 0;
        else if ( x > key[0] && x < key[1] )
            temp = 1;
        else
            temp = 2;
    }

    return temp;
}
B_tree makeNode(int x)
{
    B_tree temp = (B_tree)malloc(sizeof(struct B_node));
    temp->key[0] = x;
    temp->n_keys = 1;
    temp->leaf = 1;

    return temp;
}
B_tree createNode(void)
{
    B_tree temp = (B_tree)malloc(sizeof(struct B_node));
    temp->leaf = 1;
    temp->n_keys = 0;
    int i;
    for ( i = 0; i < order; i++ )
        temp->child[i] = NULL;
    return temp;
}

B_tree internalInsert(B_tree T, int x, int *mid)
{
    int temp;
    int m;
    B_tree T2;

    temp = searchIndex(T->key, T->n_keys, x);

    if ( temp < T->n_keys && T->key[temp] == x)
        return 0;
    if ( T->leaf == 1 )
    {
        int i;
        for ( i = T->n_keys; i > temp; i-- )
        {
            T->key[i] = T->key[i - 1];
        }

        T->key[temp] = x;
        T->n_keys += 1;
    }
    else
    {
        T2 = internalInsert(T->child[temp], x, &m);

        if ( T2 != 0 )
        {
            memmove(&T->key[temp + 1], &T->key[temp], sizeof(*(T->key)) * (T->n_keys - temp));
            memmove(&T->child[temp + 2], &T->child[temp + 1], sizeof(*(T->key)) * (T->n_keys - temp));

            T->key[temp] = m;
            T->child[temp + 1] = T2;
            T->n_keys += 1;
        }
    }

    if ( T->n_keys >= order )
    {
        m = T->n_keys / 2;
        *mid = T->key[m];

        T2 = createNode();

        T2->n_keys = T->n_keys - m - 1;
        T2->leaf = T->leaf;

        memmove(T2->key, &T->key[m + 1], sizeof(*(T->key)) * T2->n_keys);
        if ( T->leaf == 0 )
        {
            memmove(T2->child, &T->child[m + 1], sizeof(*(T->child)) * (T2->n_keys + 1));
        }

        T->n_keys = m;
        return T2;
    }
    else
    {
        return 0;
    }
}
B_tree Insert(int x, B_tree T)
{
    B_tree T1;
    B_tree T2;
    int mid;

    T2 = internalInsert(T, x, &mid);

    if ( T2 != 0 )
    {
        T1 = createNode();

        memmove(T1, T, sizeof(*T));

        T->n_keys = 1;
        T->leaf = 0;
        T->key[0] = mid;
        T->child[0] = T1;
        T->child[1] = T2;
    }
    return T;
}

void inorder(B_tree root)
{
    if ( root != 0 )
    {
        int i;
        for ( i = 0; i < root->n_keys; i++ )
        {
            inorder(root->child[i]);
            printf("%d ", root->key[i]);
            fprintf(w_fp, "%d ", root->key[i]);
        }
        inorder(root->child[i]);
    }
}



