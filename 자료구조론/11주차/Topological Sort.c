#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *r_fp;
FILE *w_fp;

typedef struct Node
{
    int value;
    int index;
    int used;
}Node;
struct GraphStruct
{
    int size;
    Node *nodes;
    int **matrix;
};
typedef struct GraphStruct *Graph;

typedef struct queue
{
    int front;
    int rear;
    int size;
    int capacity;
    int *arr;
}queue;
typedef queue *que;


int FindIndex(Node *nodes, int value);
Graph CreateGraph(int *nodes);
Graph InsertEdge(Graph G, int a, int b);
void Topsort(Graph G);
Graph DeleteGraph(Graph G);

que MakeNewQueue(int size);
void Enqueue(que q, int e);
int Dequeue(que q);
que DeleteQueue(que q);

int nodeCount = 0;

void TestPrinting(Graph g)
{
    printf("Adjacency matrix\n");
    fprintf(w_fp, "Adjacency matrix\n");
    int size = g->size;
    int i, j;
    printf("  ");
    fprintf(w_fp, "  ");
    for ( i = 1; i <= size; i++ )
    {
        printf("%d ", g->matrix[0][i]);
        fprintf(w_fp, "%d ", g->matrix[0][i]);
    }
    printf("\n");
    fprintf(w_fp, "\n");

    for ( i = 1; i <= size; i++ )
    {
        printf("%d ", g->matrix[i][0]);
        fprintf(w_fp, "%d ", g->matrix[i][0]);
        for ( j = 1; j <= size; j++ )
        {
            printf("%d ", g->matrix[i][j]);
            fprintf(w_fp, "%d ", g->matrix[i][j]);
        }
        printf("\n");
        fprintf(w_fp, "\n");
    }

    printf("\n\n");
    fprintf(w_fp, "\n\n");
    return;
}
int main(void)
{
    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    char temp[4];
    int a, b, matrixMake;
    int *nodes = (int *)malloc(sizeof(int) * 10);
    matrixMake = 0;
    Graph g = NULL;
    que q = NULL;

    while ( fscanf(r_fp, "%s", temp) != EOF )
    {
        // Link nodes
        if ( temp[1] == '-' )
        {
            if ( matrixMake == 0 )
            {
                matrixMake = 1;
                g = CreateGraph(nodes);
                q = MakeNewQueue(nodeCount);
            }
            a = temp[0] - '0';
            b = temp[2] - '0';

            g = InsertEdge(g, a, b);
        }
        // Make a matrix
        else
        {
            nodes[nodeCount++] = temp[0] - '0';
        }
    }

    TestPrinting(g);
    Topsort(g);
    DeleteGraph(g);
    DeleteQueue(q);
    free(nodes);
    fclose(r_fp);
    fclose(w_fp);
    system("pause");
    return 0;
}

Graph CreateGraph(int *nodes)
{
    Graph g = NULL;
    g = (Graph)malloc(sizeof(struct GraphStruct));
    g->size = nodeCount;
    g->matrix = (int **)malloc(sizeof(int *) * (nodeCount + 1));
    int i, j;
    for ( i = 0; i <= nodeCount; i++ )
    {
        g->matrix[i] = (int *)malloc(sizeof(int) * (nodeCount + 1));
        if ( i == 0 )
        {
            g->matrix[i][0] = 0;
            for ( j = 1; j <= nodeCount; j++ )
                g->matrix[i][j] = nodes[j - 1];
        }
        else
        {
            g->matrix[i][0] = nodes[i - 1];
            for ( j = 1; j <= nodeCount; j++ )
                g->matrix[i][j] = 0;
        }
    }

    g->nodes = (Node *)malloc(sizeof(Node) * (10));
    for ( i = 0; i < nodeCount; i++ )
    {
        g->nodes[i].index = i + 1;
        g->nodes[i].value = nodes[i];
        g->nodes[i].used = 0;
    }

    return g;
}
Graph InsertEdge(Graph G, int a, int b)
{
    int temp_a, temp_b;
    temp_a = temp_b = 0;
    for ( int i = 0; i < G->size; i++ )
    {
        if ( G->nodes[i].value == a )
        {
            temp_a = G->nodes[i].index;
        }
        if ( G->nodes[i].value == b )
        {
            temp_b = G->nodes[i].index;
        }
    }

    G->matrix[temp_a][temp_b] = 1;
    return G;
}
void Topsort(Graph G)
{
    int i, j, found, temp_index;
    que q;
    q = MakeNewQueue(nodeCount);

    for ( i = 1; i <= nodeCount; i++ )
    {
        found = 0;
        for ( j = 1; j <= nodeCount; j++ )
        {
            if ( G->matrix[j][i] == 1 )
            {
                found = 1;
                break;
            }
        }
        if ( found == 0 )
        {
            temp_index = FindIndex(G->nodes, G->matrix[0][i]);
            G->nodes[temp_index - 1].used = 1;
            Enqueue(q, G->matrix[0][i]);
        }
    }

    printf("TopSort Result : ");
    fprintf(w_fp, "TopSort Result : ");
    while ( q->size != 0 )
    {
        int x = Dequeue(q);
        printf("%d ", x);
        fprintf(w_fp, "%d ", x);
        temp_index = FindIndex(G->nodes, x);

        i = temp_index;
        for ( j = 1; j <= G->size; j++ )
            G->matrix[i][j] = 0;

        for ( i = 1; i <= nodeCount; i++ )
        {
            found = 0;
            for ( j = 1; j <= nodeCount; j++ )
            {
                if ( G->matrix[j][i] == 1 )
                {
                    found = 1;
                    break;
                }
            }
            if ( found == 0 )
            {
                temp_index = FindIndex(G->nodes, G->matrix[0][i]);
                if ( G->nodes[temp_index - 1].used == 0 )
                {
                    G->nodes[temp_index - 1].used = 1;
                    Enqueue(q, G->matrix[0][i]);
                }
            }
        }
    }
    printf("\n");
    fprintf(w_fp, "\n");
}
Graph DeleteGraph(Graph G)
{
    int size = G->size;
    int i;
    for ( i = 0; i < size; i++ )
    {
        free(G->matrix[i]);
    }
    free(G->matrix);
    free(G->nodes);
    free(G);
    return NULL;
}
int FindIndex(Node *nodes, int value)
{
    int i;
    for ( i = 0; i < nodeCount; i++ )
    {
        if ( nodes[i].value == value )
            return nodes[i].index;
    }

    return -1;
}
que MakeNewQueue(int size)
{
    que temp = (que)malloc(sizeof(queue));
    if ( temp == NULL )
    {
        printf("error!\n");
        return NULL;
    }

    temp->arr = (int *)malloc(sizeof(int) * size);
    if ( temp->arr == NULL )
    {
        printf("error!\n");
    }

    temp->capacity = size;
    temp->size = 0;
    temp->front = 1;
    temp->rear = 0;

    return temp;
}
void Enqueue(que q, int e)
{
    if ( q->size == q->capacity )
    {
        fprintf(w_fp, "Full\n");
        printf("Full\n");
        return;
    }

    q->arr[(++q->rear) % q->capacity] = e;
    ++q->size;
    return;
}
int Dequeue(que q)
{
    if ( q->size == 0 )
    {
        fprintf(w_fp, "Empty\n");
        printf("Empty\n");
        return 0;
    }

    int e = q->arr[(q->front++) % q->capacity];
    --q->size;

    return e;
}
que DeleteQueue(que q)
{
    free(q->arr);
    free(q);
    return NULL;
}