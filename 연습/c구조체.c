#include <stdio.h>
#include <stdlib.h>
struct A{
    int a;
};
int main(void)
{
    struct A A;
    A.a = 10;

 
    printf("A.a : %d\n", A.a);
    system("pause");
    return 0;
}