#include <stdio.h>
int main(void)
{
    int n, i, j;
    printf("何段の三角形ですか？->");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
}