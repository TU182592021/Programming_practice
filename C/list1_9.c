#include <stdio.h>

int main(void)
{
    int n, i, sum = 0;

    do
    {
        printf("整数->");
        scanf("%d", &n);
    } while (n < 0);
    for (i = 0; i <= n; i++)
    {
        sum += i;
    }
    printf("1から%dまでの和は%dです。", n, sum);

    return 0;
}