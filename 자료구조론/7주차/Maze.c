#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int v;
    int p;
    int right;
    int left;
    int down;
    int up;
}Node;
typedef struct E
{
    int a;
    int b;
    int dir; // 0: down, 1: right
}E;
FILE *r_fp;
FILE *w_fp;
int SET_COUNT;

Node *makeUni(int n);
int find(Node *U, int a);
void uni(Node *U, int a, int b);
void makeMiro(Node *U, int size);
E *makeEdge(int size);
int *makeEdgeFlag(Node *U, E *edge, int size);
void printMiro(Node *U, int n);
int main(void)
{
    srand((unsigned int)time(NULL));
    // x = rand() % 10;

    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    int n;
    fscanf(r_fp, "%d", &n);
    SET_COUNT = n * n;

    Node *U = makeUni(n);
    makeMiro(U, n);
    printMiro(U, n);
    fclose(r_fp);
    fclose(w_fp);

    // free
    free(U);

    system("pause");
    return 0;
}

Node *makeUni(int n)
{
    Node *U = (Node *)malloc(sizeof(Node) * n * n);
    int i;
    for ( i = 0; i < n * n; i++ )
    {
        U[i].p = i;
        U[i].v = i;
        U[i].right = 0;
        U[i].down = 0;
        U[i].up = 0;
        U[i].left = 0;
    }

    U[0].left = 1;
    U[n * n - 1].right = 1;
    return U;
}
int find(Node *U, int a)
{
    if ( U[a].p == U[a].v )
        return U[a].v;
    else
        return U[a].p = find(U, U[a].p);
}
void uni(Node *U, int a, int b)
{
    int tempA = find(U, a);
    int tempB = find(U, b);

    if ( tempA < tempB )
    {
        U[tempB].p = tempA;
    }
    else if ( tempA > tempB )
    {
        U[tempA].p = tempB;
    }
    else
    {
        return;
    }
}
void makeMiro(Node *U, int size)
{
    int edgeSize;
    edgeSize = (2 * (size - 1) + 1) * (size - 1) + (size - 1);


    E *edge = makeEdge(size);
    int *edgeFlag = makeEdgeFlag(U, edge, size);


    while ( SET_COUNT > 1 )
    {
        int selectEdge = rand() % edgeSize;
        if ( edgeFlag[selectEdge] != 0 )
        {
            continue;
        }

        edgeFlag[selectEdge] = 1;
        int a = edge[selectEdge].a;
        int b = edge[selectEdge].b;

        int p_a = find(U, a);
        int p_b = find(U, b);

        if ( p_a != p_b )
        {
            SET_COUNT--;
            uni(U, a, b);
            if ( edge[selectEdge].dir == 0 ) // down
            {
                U[edge[selectEdge].a].down = 1;
                U[edge[selectEdge].b].up = 1;
            }
            else    // right
            {
                U[edge[selectEdge].a].right = 1;
                U[edge[selectEdge].b].left = 1;
            }
        }
    }

    free(edge);
    free(edgeFlag);
    return;
}
E *makeEdge(int size)
{
    int E_size = (2 * (size - 1) + 1) * (size - 1) + (size - 1);
    E *temp = (E *)malloc(sizeof(E) * E_size);
    int i, j, idx;

    int **tempNum = (int **)malloc(sizeof(int *) * size);
    for ( i = 0; i < size; i++ )
    {
        tempNum[i] = (int *)malloc(sizeof(int) * size);
    }

    int num = 0;
    for ( i = 0; i < size; i++ )
    {
        for ( j = 0; j < size; j++ )
        {
            tempNum[i][j] = num++;
        }
    }

    idx = 0;
    for ( i = 0; i < size - 1; i++ )
    {

        for ( j = 0; j < size - 1; j++ )
        {
            temp[idx].a = tempNum[i][j];
            temp[idx].b = tempNum[i + 1][j];
            temp[idx].dir = 0;
            idx++;

            temp[idx].a = tempNum[i][j];
            temp[idx].b = tempNum[i][j + 1];
            temp[idx].dir = 1;
            idx++;
        }
 
        temp[idx].a = tempNum[i][j];
        temp[idx].b = tempNum[i + 1][j];
        temp[idx].dir = 0;
        idx++;
    }

    for ( j = 0; j < size - 1; j++ )
    {
        temp[idx].a = tempNum[i][j];
        temp[idx].b = tempNum[i][j + 1];
        temp[idx].dir = 1;
        idx++;
    }

    // free
    for(i = 0; i < size; i++)
    {
        free(tempNum[i]);
    }
    free(tempNum);

    return temp;
}
int *makeEdgeFlag(Node *U, E *edge, int size)
{
    int E_size = (2 * (size - 1) + 1) * (size - 1) + (size - 1);
    int *temp = (int *)malloc(sizeof(int) * E_size);
    int i;
    for ( i = 0; i < E_size; i++ )
    {
        temp[i] = 0;
    }

    return temp;
}
void printMiro(Node *U, int n)
{
    int i, j;
    int size = n * n;
    for ( i = 0; i < size; i++ )
    {
        int temp = i;
        for ( j = 0; j < n; j++ )
        {
            printf("*");
            fprintf(w_fp, "*");
            if ( U[temp].up == 0 )
            {
                printf("-");
                fprintf(w_fp, "-");
            }
            else
            {
                printf(" ");
                fprintf(w_fp, " ");
            }
            temp++;
        }
        printf("*\n");
        fprintf(w_fp, "*\n");

        temp = i;
        for ( j = 0; j < n; j++ )
        {
            if ( U[temp].left == 0 )
            {
                printf("|");
                fprintf(w_fp, "|");
            }
            else
            {
                printf(" ");
                fprintf(w_fp, " ");
            }
            printf(" ");
            fprintf(w_fp, " ");
            temp++;
        }
        if ( U[temp - 1].right == 0 )
        {
            printf("|");
            fprintf(w_fp, "|");
        }
        printf("\n");
        fprintf(w_fp, "\n");
        i = temp - 1;
    }
    for ( i = 0; i < n; i++ )
    {
        printf("*");
        fprintf(w_fp, "*");
        printf("-");
        fprintf(w_fp, "-");
    }
    printf("*");
    fprintf(w_fp, "*");

    return;
}