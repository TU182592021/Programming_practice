#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("３つの整数値の最大値を求めます。\n");
    printf(" aの値->");
    scanf("%d", &a);
    printf("bの値->");
    scanf("%d", &b);
    printf("cの値->");
    scanf("%d", &c);

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
    printf("最大値は%dです。\n", max);
    return 0;
}