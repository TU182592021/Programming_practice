#include <stdio.h>

int main(void)
{
    int a, b, num;
    do
    {
        printf("初めの整数->");
        scanf("%d", &a);
        printf("終わりの整数->");
        scanf("%d", &b);
    } while (b < a);
    num = b - a;
    printf("%d", num);
}