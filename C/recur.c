#include <stdio.h>

/*--- 整数値nの階乗を返却 ---*/
int factorial(int n)
{
    int fact = 1;
    printf("  factorial(%d)\n", n);
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            fact = fact * (n - i);
        }
        return fact;
    }
    else
        return 1;
}

/*--- 整数値x, yの最大公約数を返却する ---*/
int gcd(int x, int y)
{
    printf("  gcd(%d, %d)\n", x, y);
    if (y == 0)
        return x;
    int t, z;
    if (y > x)
    {
        t = y;
        y = x;
        x = t;
    }
    z = x % y;
    while (z != 0)
    {
        x = y;
        y = z;
        z = x % y;
    }
    return y;
}

int main()
{
    int x, y;

    puts("階乗を求めます。");
    printf("整数を入力せよ：");
    scanf("%d", &x);
    printf("%dの階乗は%dです。\n\n", x, factorial(x));

    puts("二つの整数の最大公約数を求めます。");
    printf("整数を入力せよ：");
    scanf("%d", &x);
    printf("整数を入力せよ：");
    scanf("%d", &y);
    printf("最大公約数は%dです。\n\n", gcd(x, y));
}