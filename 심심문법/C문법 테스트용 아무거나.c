#include <stdio.h>

int main(void)
{
    int a;
    char b[10];
    char c;
    scanf("%d", &a);
    scanf("%c", &c);
    scanf("%s", b);

    printf("a : %d\n", a);
    printf("c : %c\n", c);
    printf("b : %s\n", b);

    system("pause");
    return 0;
}