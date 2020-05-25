#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *r_fp;
FILE *w_fp;
typedef struct stack
{
    int *arr;
    int maxSize;
    int topOfStack;
}stack;

stack* createStack(int size)
{
    stack *stk = (stack*)malloc(sizeof(stack));
    if(stk == NULL)
    {
        printf("error, out of space\n");
        return stk;
    }

    stk->arr = (int*)malloc(sizeof(int) * size);
    if(stk->arr == NULL)
    {
        printf("error, out of space\n");
        return stk;
    }

    stk->maxSize = size;
    stk->topOfStack = -1;
    return stk;
}

void push(stack* stk, int e)
{
    if(stk->maxSize -1 == stk->topOfStack)
    {
        fprintf(w_fp, "%s", "Full\n");
        printf("Full\n");
        return;
    }
    
    stk->arr[++stk->topOfStack] = e; 
    return;
}
int pop(stack* stk)
{
    if(stk->topOfStack == -1)
    {
        fprintf(w_fp, "%s", "Empty\n");
        printf("Empty\n");
        return 0;
    }

    return stk->arr[stk->topOfStack--];
}

int main(void)
{
    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");

    int num = 0;
    char input[20];
    fscanf(r_fp, "%d\n", &num);
    
    stack* stk = createStack(100);
    int n = 0;
    for(; n < num; n++)
    {
        fgets(input, 20, r_fp);
        if(input[1] == 'u')
        {
            char inputNum[20];
            int element = 0;
            int i = 5;
            int j = 0;
            for(; input[i] != '\n'; ++i)
            {
                inputNum[j] = input[i];
                ++j;
            }

            int digit = 1;
            --j;
            for(;j >= 0; --j)
            {
                element += (inputNum[j] - '0') * digit;
                digit *= 10;
            }

            push(stk, element);
        }
        else if(input[1] == 'o')
        {
            int popElement = pop(stk);
            if(popElement != 0)
            {
                fprintf(w_fp, "%d\n", popElement);
                printf("%d\n", popElement);
            }
        }
    }

    fclose(w_fp);
    fclose(r_fp);
    system("pause");
    return 0;
}