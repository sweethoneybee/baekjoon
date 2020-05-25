#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *widget = (int*)malloc(10 * sizeof(int));
    int i;
    for(i = 0 ; i < 10; i++)
    {
        widget[i] = i + 1;
    }

    printf("before realloc\n");
    printf("address : %o\n", widget);
    for(i = 0; i < 10; i++)
    {
        printf("%d ", widget[i]);
    }
    printf("\n");
    realloc(widget, 20);

    printf("after realloc\n");
    printf("address : %o\n", widget);
    for(i = 0; i < 10; i++)
    {
        printf("%d ", widget[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}