#include <stdio.h>

int max4(int a, int b, int c, int d)
{
    int max = 0;
    max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    if (d > max)
    {
        max = d;
    }

    return max;
}

int main(void)
{
    int a, b, c, d;

    printf("%d", max4(2, 3, 5, 4));
    return 0;
}