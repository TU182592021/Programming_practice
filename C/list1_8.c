#include <stdio.h>

int main(void)
{
    int n, i, sum = 0;
    printf("整数->");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        sum += i;
    }
    printf("1から%dまでの和は%dです。", n, sum);
    return 0;
}