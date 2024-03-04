#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
    int i = 0;
    a[n] = key;
    while (1)
    {
        if (a[i] == key)

            break;
        ++i;
    }
    return i == n ? -1 : i;
}

int main(void)
{
    int nx, ky;

    printf("要素数は : ");
    scanf("%d", &nx);

    int *x = calloc(nx + 1, sizeof(int));

    printf("数値を入力してください\n");
    for (int i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("探す数値を入力してください : ");
    scanf("%d", &ky);

    int idx = search(x, nx, ky);

    if (idx == -1)
        printf("探索に失敗しました");
    else
        printf("%dはx[%d]に格納されています", ky, idx);

    free(x);

    return 0;
}