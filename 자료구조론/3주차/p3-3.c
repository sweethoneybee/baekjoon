#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *r_fp;
FILE *w_fp;

struct charStack
{
    char *arr;
    int maxSize;
    int topOfStack;
};
typedef struct charStack* charStack;
struct intStack
{
    int *arr;
    int maxSize;
    int topOfStack;
};
typedef struct intStack* intStack;

charStack createCharStack(int size);
void pushChar(charStack stk, char e);
char popChar(charStack stk);
int charEmpty(charStack stk);
char charTop(charStack stk);
intStack createIntStack(int size);
void pushInt(intStack stk, int e);
int popInt(intStack stk);
int intEmpty(intStack stk);
int intTop(intStack stk);
int precedence(char temp);

int main(void)
{
    r_fp = fopen("input.txt", "r");
    w_fp = fopen("output.txt", "w");
    char input[101];
    char operating[101];
    fscanf(r_fp, "%s\n", input);
    
    fprintf(w_fp, "Infix Form : %s\n", input);
    printf("Infix Form : %s\n", input);

    charStack c_stk = createCharStack(101);
    intStack i_stk = createIntStack(101);
    intStack oper_stk = createIntStack(101);
    pushChar(c_stk, '0');
    pushInt(i_stk, -2);

    int i = 0;
    int j = 0;
    for(; input[i] != '#'; i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            operating[j++] = input[i];
        }
        else if(input [i] == '(')
        {
            pushChar(c_stk, '(');
            pushInt(i_stk, -1);
        }
        else
        {
            int pre = precedence(input[i]);
            if(input[i] == ')')
            {
                while(charTop(c_stk) != '(')
                {
                    operating[j++] = charTop(c_stk);
                    popChar(c_stk);
                    popInt(i_stk);
                }
                popChar(c_stk);
                popInt(i_stk);
            }
            else if(intTop(i_stk) < pre)
            {
                pushChar(c_stk, input[i]);
                pushInt(i_stk, pre);
            }
            else
            {
                while(intTop(i_stk) >= pre)
                {
                    operating[j++] = popChar(c_stk);
                    popInt(i_stk);
                }
                pushChar(c_stk, input[i]);
                pushInt(i_stk, pre);
            }
        }
    }
    while(charTop(c_stk) != '0')
    {
        operating[j++] = popChar(c_stk);
        popInt(i_stk);
    }
    
    operating[j] = '\0';
    fprintf(w_fp, "Postfix Form : %s\n", operating);
    printf("Postfix Form : %s\n", operating);

    int answer = 0;
    i = 0;
    for(; operating[i] != '\0'; i++)
    {
        if(operating[i] < '0' || operating[i] > '9')
        {
            int b = intTop(oper_stk);
            popInt(oper_stk);
            int a = intTop(oper_stk);
            popInt(oper_stk); 
            int pushTemp = 0;
            switch (operating[i])
            {
                case '*':
                    pushTemp = a * b;
                    break;
                case '/':
                    pushTemp = a / b;
                    break;
                case '%':
                    pushTemp = a % b;
                    break;
                case '+':
                    pushTemp = a + b;
                    break;
                case '-':
                    pushTemp = a - b;
                    break;
                default :
                    break;
            }
            pushInt(oper_stk, pushTemp);
        }
        else
        {
            pushInt(oper_stk, operating[i] - '0');
        }
    }

    answer = intTop(oper_stk);

    fprintf(w_fp, "Evaluation Result : %d\n", answer);
    printf("Evaluation Result : %d\n", answer);

    fclose(r_fp);
    fclose(w_fp);
    system("pause");
    return 0;
}

charStack createCharStack(int size)
{
    charStack stk = (charStack)malloc(sizeof(charStack));
    if(stk == NULL)
    {
        printf("error, out of space\n");
        return stk;
    }

    stk->arr = (char*)malloc(sizeof(char) * size);
    if(stk->arr == NULL)
    {
        printf("error, out of space\n");
        return stk;
    }

    stk->maxSize = size;
    stk->topOfStack = -1;
    return stk;
}

void pushChar(charStack stk, char e)
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
char popChar(charStack stk)
{
    if(charEmpty(stk) == 1)
    {
        fprintf(w_fp, "%s", "Empty\n");
        printf("Empty\n");
        return 0;
    }

    return stk->arr[stk->topOfStack--];
}

int charEmpty(charStack stk)
{
    if(stk->topOfStack == -1)
    {
        return 1;
    }
    return 0;
}

char charTop(charStack stk)
{
    return stk->arr[stk->topOfStack];
}


intStack createIntStack(int size)
{
    intStack stk = (intStack)malloc(sizeof(intStack));
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

void pushInt(intStack stk, int e)
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
int popInt(intStack stk)
{
    if(intEmpty(stk) == 1)
    {
        fprintf(w_fp, "%s", "Empty\n");
        printf("Empty\n");
        return 0;
    }

    return stk->arr[stk->topOfStack--];
}

int intEmpty(intStack stk)
{
    if(stk->topOfStack == -1)
    {
        return 1;
    }
    return 0;
}

int intTop(intStack stk)
{
    return stk->arr[stk->topOfStack];
}

int precedence(char temp)
{
    if(temp == '*' || temp == '/' || temp == '%')
    {
        return 2;
    }
    else if(temp == ')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}