#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999;

typedef struct Node
{
    int key;
    int weight;
}Node;
typedef struct HeapStruct *Heap;
typedef struct HeapStruct
{
    int Capacity;
    int Size;
    Node *elements;
}HeapStruct;

Heap CreateMinMheap(int heapSize);
void Insert(Heap H, int vertex, int distance);
Node DeleteMin(Heap H);
void PrintShortestPath(int *pred);
void FindShortestPath(Heap H);
void decreasePriority(Heap H, int vertex, int weight);

FILE *r_fp;
FILE *w_fp;
int v1, v2, v3, prev, start, end;
int count_edge;
int pred[101] = { 0 };
int weight[101] = { 0 };
int w[101][101] = { 0 };
int main(void)
{
    int i, j;
    for ( i = 0; i <= 100; i++ )
    {
        for ( j = 0; j <= 100; j++ )
            w[i][j] = 0;
    }
    for ( i = 0; i <= 100; i++ )
    {
        weight[i] = INF;
    }
    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");


    while ( fscanf(r_fp, "%d", &v1) != EOF )
    {
        if ( v1 < 0 )
            break;
        prev = v1;
        count_edge += 1;
    }
    count_edge -= 1;
    v2 = -v1;
    v1 = prev;
    fscanf(r_fp, "%d", &v3);
    v3 = -v3;
    w[v1][v2] = v3;

    while ( fscanf(r_fp, "%d", &v1) != EOF )
    {
        if ( fscanf(r_fp, "%d", &v2) == EOF || v2 > 0 )
            break;
        if ( fscanf(r_fp, "%d", &v3) == EOF )
            break;

        v2 = -v2;
        v3 = -v3;
        w[v1][v2] = v3;
    }

    // v1 is start vertex, v2 is end vertex.
    start = v1; end = v2;

    Heap h = CreateMinMheap(101);
    int bigNum = 99999;
    for ( i = 1; i <= count_edge; i++ )
    {
        if ( i == start )
            continue;
        Insert(h, i, bigNum);
    }
    Insert(h, v1, 0);
    weight[v1] = 0;

    FindShortestPath(h);
    PrintShortestPath(pred);

    system("pause");
    return 0;
}


Heap CreateMinMheap(int heapSize)
{
    Heap temp = (Heap)malloc(sizeof(HeapStruct));
    temp->Capacity = heapSize;
    temp->Size = 0;
    temp->elements = (Node *)malloc(sizeof(Node) * (temp->Capacity + 1));
    return temp;
}
void Insert(Heap H, int vertex, int distance)
{
    Node *e = H->elements;
    int i;

    if ( H->Size == H->Capacity )
    {
        printf("heap is full.\n");
        fprintf(w_fp, "heap is full.\n");
    }
    for ( i = 1; i <= H->Size; i++ )
    {
        if ( e[i].key == vertex )
        {
            printf("%d is already in the tree.\n", vertex);
            fprintf(w_fp, "%d is already in the tree.\n", vertex);
            return;
        }
    }

    for ( i = ++H->Size; i > 1 && H->elements[i / 2].weight > distance; i /= 2 )
    {
        //H->elements[i] = H->elements[i/2];
        H->elements[i].key = H->elements[i / 2].key;
        H->elements[i].weight = H->elements[i / 2].weight;
    }
    H->elements[i].key = vertex;;
    H->elements[i].weight = distance;

    //printf("insert vertex: %d, distance: %d\n", H->elements[i].key, H->elements[i].weight);
    return;
}

Node DeleteMin(Heap H)
{
    Node value = H->elements[1];

    int temp_k, temp_w;
    temp_k = H->elements[1].key;
    temp_w = H->elements[1].weight;

    H->elements[1].key = H->elements[H->Size].key;
    H->elements[1].weight = H->elements[H->Size].weight;

    H->elements[H->Size].key = temp_k;
    H->elements[H->Size].weight = temp_w;

    H->Size -= 1;

    int i = 1;
    while ( 1 )
    {
        int temp = i;
        int left = i * 2;
        int right = i * 2 + 1;

        if ( left <= H->Size && H->elements[temp].weight > H->elements[left].weight )
            temp = left;
        if ( right <= H->Size && H->elements[temp].weight > H->elements[right].weight )
            temp = right;

        if ( temp == i )
            break;

        temp_k = H->elements[temp].key;
        temp_w = H->elements[temp].weight;

        H->elements[temp].key = H->elements[i].key;
        H->elements[temp].weight = H->elements[i].weight;

        H->elements[i].key = temp_k;
        H->elements[i].weight = temp_w;

        i = temp;
    }

    return value;
}

void PrintShortestPath(int *pred)
{
    int count = 0;
    if ( pred[end] == 0 )
    {
        printf("no path\n");
        fprintf(w_fp, "no path\n");
        return;
    }

    int *tempArr = (int *)malloc(sizeof(int) * 100);
    int temp = end;
    tempArr[count++] = end;
    while ( pred[temp] != start )
    {
        tempArr[count++] = pred[temp];
        temp = pred[temp];
    }
    tempArr[count++] = pred[temp];

    int i;
    for ( i = count - 1; i >= 0; i-- )
    {
        printf("%d ", tempArr[i]);
        fprintf(w_fp, "%d ", tempArr[i]);
    }
    printf("\n");
    fprintf(w_fp, "\n");

    free(tempArr);
    return;
}
void FindShortestPath(Heap H)
{
    while ( H->Size != 0 )
    {
        Node u = DeleteMin(H);
        int temp_v, temp_w, i, j;
        temp_v = u.key;
        temp_w = u.weight;

        i = temp_v;
        for ( j = 1; j <= 100; j++ )
        {
            if ( w[i][j] != 0 )
            {
                if ( weight[i] + w[i][j] < weight[j] )
                {
                    weight[j] = weight[i] + w[i][j];
                    pred[j] = i;
                    decreasePriority(H, j, weight[j]);
                }
            }
        }
    }
}

void decreasePriority(Heap H, int vertex, int weight)
{
    int i, temp_k, temp_w;
    for ( i = 1; i <= 100; i++ )
    {
        if ( H->elements[i].key == vertex )
            break;
    }
    H->elements[i].weight = weight;
    while ( 1 )
    {
        int temp = i;
        int parent = i / 2;

        if ( parent <= H->Size && H->elements[temp].weight < H->elements[parent].weight )
            temp = parent;
        else
            break;

        temp_k = H->elements[temp].key;
        temp_w = H->elements[temp].weight;

        H->elements[temp].key = H->elements[i].key;
        H->elements[temp].weight = H->elements[i].weight;

        H->elements[i].key = temp_k;
        H->elements[i].weight = temp_w;

        i = temp;

        if ( temp == 1 )
            break;
    }
    return;
}