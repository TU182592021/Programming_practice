#include <stdio.h>

int main(void)
{
    int n, i, sum = 0;
    printf("整数->");
    scanf("%d", &n);
    i = 0;
    while (i <= n)
    {
        sum += i;
        ++i;
    }
    printf("1から%dまでの和は%dです。", n, sum);
    return 0;
}