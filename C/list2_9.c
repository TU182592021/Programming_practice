#include <stdio.h>

int main(void)
{
    unsigned long counter = 0; // unsigned型は非負の整数を格納する。その分表せる数が増える。

    for (int n = 2; n <= 1000; n++)
    {
        int i;

        for (i = 2; i < n; i++)
        {
            counter++;
            if (n % i == 0)
                break;
        }
        if (i == n)
        {
            printf("%d\n", n);
        }
    }
    printf("除算を行った回数は%lu回です。", counter); // unsigned型は%lufで表す。
    return 0;
}