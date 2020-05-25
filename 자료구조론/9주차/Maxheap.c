#include <stdio.h>
#include <stdlib.h>
FILE* r_fp;
FILE* w_fp;

typedef struct HeapStruct* Heap;
typedef struct HeapStruct
{
    int Capacity;
    int Size;
    int *Elements;
}HeapStruct;

void Insert(int x, Heap H);
void Find(int x, Heap H);
void Print(Heap H);

int main(void)
{

    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    char oper[3];
    int value, maxHeapSize;

    fscanf(r_fp, "%d", &maxHeapSize);
    Heap H = (Heap)malloc(sizeof(HeapStruct));
    H->Capacity = maxHeapSize;
    H->Size = 0;
    // Heap's first index starts at 1
    H->Elements = (int*)malloc(sizeof(int) * (H->Capacity + 1));

    while ( fscanf(r_fp, "%s", oper) != EOF )
    {
        // Print Heap in index order
        if ( oper[0] == 'p' )
        {
            Print(H);
            printf("\n");
            fprintf(w_fp, "\n");
            continue;
        }

        // Insert value
        if ( oper[0] == 'i' )
        {
            fscanf(r_fp, "%d\n", &value);
            Insert(value, H);
        }
        // Find value
        if ( oper[0] == 'f' )
        {
            fscanf(r_fp, "%d\n", &value);
            Find(value, H);
        }
    }

    free(H->Elements);
    free(H);
    fclose(w_fp);
    fclose(r_fp);
    
    // for test
    system("pause");
    return 0;
}

void Insert(int x, Heap H)
{
    int *e = H->Elements;
    int i;

    if(H->Size == H->Capacity)
    {
        printf("heap is full.\n");
        fprintf(w_fp, "heap is full.\n");
    }
    for(i = 1; i <= H->Size; i++)
    {
        if(e[i] == x)
        {
            printf("%d is already in the tree.\n", x);
            fprintf(w_fp, "%d is already in the tree.\n", x);
            return;
        }
    }
    
    for(i = ++H->Size; i > 1 && H->Elements[i/2] < x; i /= 2)
    {
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = x;
    
    printf("insert %d\n", x);
    fprintf(w_fp, "insert %d\n", x);
    return;
}
void Find(int x, Heap H)
{
    int i;
    for(i = 1; i <= H->Size; i++)
    {
        if(H->Elements[i] == x)
        {
            printf("%d is in the heap.\n", x);
            fprintf(w_fp, "%d is in the heap.\n", x);
            return;
        }
    }

    printf("%d is not in the heap.\n", x);
    fprintf(w_fp, "%d is not in the heap.\n", x);
    return;
}
void Print(Heap H)
{
    int i;
    for(i = 1; i <= H->Size; i++)
    {
        printf("%d ", H->Elements[i]);
        fprintf(w_fp, "%d ", H->Elements[i]);
    }
    return;
}
