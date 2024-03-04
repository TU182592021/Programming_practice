#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int na;

    printf("要素数->");
    scanf("%d", &na);

    int *a = calloc(na, sizeof(int));

    if (a == NULL)
    {
        printf("必要な領域を確保できませんでした。");
    }
    else
    {
        for (int i; i < na; i++)
        {
            printf("%d個の整数を入力してください。->", na);
            scanf("%d", &a[i]);
        }

        printf("各要素の値は次の通りです。\n");

        for (int i = 0; i < na; i++)
        {
            printf("a[%d] : %d\n", i, a[i]);
        }
        free(a);
    }
    return 0;
}