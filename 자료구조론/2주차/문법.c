#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char a[10];
    char b[10];

    scanf("%s", a);
    scanf("%s", b);
    printf("a : %s\n", a);
    printf("b : %s\n", b);
    if(strcmp(a, b) > 0)
    {
        printf("a is bigger\n");
    }
    else if(strcmp(a, b) < 0)
    {
        printf("b is bigger\n");
    }
    else if(strcmp(a, b) == 0)
    {
        printf("same\n");
    }
    system("pause");
    return 0;
}