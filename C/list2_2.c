#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};
    int na = sizeof(a) / sizeof(a[0]);

    printf("配列の要素数は%dです。\n", na);
    for (int i = 0; i < na; i++)
    {
        printf("a[%d] : %d\n", i, a[i]);
    }
}