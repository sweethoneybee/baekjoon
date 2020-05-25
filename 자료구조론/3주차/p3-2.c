#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *r_fp;
FILE *w_fp;

typedef struct queue
{
    int front;
    int rear;
    int size;
    int capacity;
    int *arr;
}queue;
typedef queue* que;

que createQueue(int size)
{
    que temp = (que)malloc(sizeof(queue));
    if(temp == NULL)
    {
        printf("error!\n");
    }

    temp->arr = (int*)malloc(sizeof(int) * size);
    if(temp->arr == NULL)
    {
        printf("error!\n");
    }

    temp->capacity = size;
    temp->size = 0;
    temp->front = 1;
    temp->rear = 0;

    return temp;
}

void enQ(que q, int e)
{
    if(q->size == q->capacity)
    {
        fprintf(w_fp, "Full\n");
        printf("Full\n");
        return;
    }

    q->arr[(++q->rear) % q->capacity] = e; 
    ++q->size;
    return;
}

int deQ(que q)
{
    if(q->size == 0)
    {
        fprintf(w_fp, "Empty\n");
        printf("Empty\n");
        return 0;
    }

    int e = q->arr[(q->front++) % q->capacity];
    --q->size;
    
    return e;
}
int main(void)
{
    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");
    que q = createQueue(100);

    int N = 0;
    fscanf(r_fp, "%d\n", &N);
    int n = 0;
    char cleaning[3];
    for(; n < N; n++)
    {
        char input[10];
        fgets(input, 4, r_fp);
        if(input[0] == 'e')
        {
            int inputNum = 0;
            fscanf(r_fp, "%d\n", &inputNum);
            enQ(q, inputNum);
        }

        else if(input[0] == 'd')
        {
            fscanf(r_fp, "%c", cleaning);
            int outputNum = -1;
            outputNum = deQ(q);

            if(outputNum != 0)
            {
                fprintf(w_fp, "%d\n", outputNum);
                printf("%d\n", outputNum);
            }
        }
    }
    
    fclose(r_fp);
    fclose(w_fp);
   
    system("pause");
    return 0;
}