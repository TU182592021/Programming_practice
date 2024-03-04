#include <stdio.h>
#include <stdlib.h>

int bin_serch(int const a[], int n, int key)
{
    int pr = n - 1, pl = 0;

    do
    {
        int pc = (pl + pr) / 2;
        if (a[pc] == key)
            return pc;
        else if (a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);
    return -1;
}

int main(void)
{
    int nx;

    puts("二分探索");
    printf("要素数 : ");
    scanf("%d", &nx);

    int *x = calloc(nx, sizeof(int));

    printf("数値を昇順に入力してください : ");
    printf("x[%d] : ");
    scanf("%d", &x[0]);
    for (int i = 1; i < nx; i++)
    {
        do
        {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }
    printf("探索する数値を入力してください : ");

    int ky, idx;

    scanf("%d", &ky);
    idx = bin_serch(x, nx, ky);
    if (idx == -1)
        printf("探索に失敗しました。");
    else
        printf("%dはx[%d]に格納されています。", ky, idx);

    free(x);
    return 0;
}