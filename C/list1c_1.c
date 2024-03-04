#include <stdio.h>

int med3(int a, int b, int c)
{
    if (a >= b)

        if (b >= c)

            return b;

        else if (a <= c)

            return a;

        else

            return c;

    else if (a > c)

        return a;

    else if (b > c)

        return c;

    else
        return b;
}

int main(void)
{
    int a, b, c;

    printf("aの値->");
    scanf("%d", &a);
    printf("bの値->");
    scanf("%d", &b);
    printf("cの値->");
    scanf("%d", &c);
    printf("%d", med3(a, b, c));

    return 0;
}