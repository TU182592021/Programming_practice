#include <stdio.h>

int main(void)
{
    int n, i, j;
    printf("整数->");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}