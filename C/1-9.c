#include <stdio.h>

int sumof(int a, int b)
{
    int i, t, sum = 0;
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    for (i = a; i <= b; i++)
    {
        sum += i;
    }
    return sum;
}

int main(void)
{
    int a, b;

    printf("初めの整数->");
    scanf("%d", &a);
    printf("終わりの整数->");
    scanf("%d", &b);
    printf("\n");
    sumof(a, b);
    printf("和は%d", sumof(a, b));

    return 0;
}