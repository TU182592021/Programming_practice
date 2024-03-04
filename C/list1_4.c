#include <stdio.h>

int main(void)
{
    int n;
    printf("好きな数値を入れてください->");
    scanf("%d", &n);

    if (n == 1)
        puts("A");
    else if (n == 2)
        puts("B");
    else
        puts("C");
}