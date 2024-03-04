#include <stdio.h>

void triangleLB(int n)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
}

void triangleRB(int n)
{
    int i, j, d, f = n, k = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= f; j++)
        {
            if (j == f)
            {
                for (d = 1; d <= k; d++)
                {
                    putchar('*');
                }
            }
            else
                putchar(' ');
        }
        putchar('\n');
        f = f - 1;
        k++;
    }
}

void triangleLU(int n)
{
    int i, j, d = n;
    for (i = 1; i <= n; i++)
    {
        for (j = d; j >= 1; j = j - 1)
            putchar('*');
        putchar('\n');
        d = d - 1;
    }
}

int triangleRU(int n)
{
    int i, j, d, f = n, k = 0;
    for (i = 1; i <= n; i++)
    {
        if (k > 0)
        {
            for (d = 1; d <= k; d++)
                putchar(' ');
        }
        for (j = 1; j <= f; j++)
            putchar('*');
        f = f - 1;
        k++;
        putchar('\n');
    }
}

int main(void)
{
    int n;
    printf("何段の三角形ですか？->");
    scanf("%d", &n);
    putchar('\n');
    triangleLB(n);
    putchar('\n');
    triangleRB(n);
    putchar('\n');
    triangleLU(n);
    putchar('\n');
    triangleRU(n);
}