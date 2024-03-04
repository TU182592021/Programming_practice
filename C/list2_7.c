#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

void ary_reverse(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(int, a[i], a[n - i - 1]);
    }
}

int main(void)
{
    int na;

    printf("人数を入力してください->");
    scanf("%d", &na);

    int *x = calloc(na, sizeof(int));

    for (int i = 0; i < na; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    ary_reverse(x, na);
    printf("要素の反転が行われました。\n");
    for (int i = 0; i < na; i++)
    {
        printf("x[%d] : %d\n", i, x[i]);
    }
    free(x);

    return 0;
}