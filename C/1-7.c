#include <stdio.h>

int main(void)
{
    int n, i, sum = 0;
    printf("整数->");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i <= n; i++)
    {
        sum += i;
        printf("%d", i);
        if (i != n)
            printf("+");
        else
            printf("=");
    }
    printf("%d", sum);
    return 0;
}