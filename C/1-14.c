#include <stdio.h>

int main(void)
{
    int n, m, i, j;

    printf("高さ->");
    scanf("%d", &n);
    printf("横->");
    scanf("%d", &m);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}