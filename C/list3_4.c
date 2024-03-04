#include <stdio.h>
#include <stdlib.h>

int int_cmp(int const *a, int const *b)
{
    if (*a < *b)
        return -1;
    else if (*a == *b)
        return 0;
    else
        return 1;
}

int main(void)
{
    int nx, ky;

    puts("bserch関数による探索");
    printf("要素数 : ");
    scanf("%d", &nx);

    int *x = calloc(nx, sizeof(int));

    puts("要素を入力してください");
    printf("x[0] : ");
    scanf("%d", &x[0]);

    for (int i = 1; i < nx; i++)
    {
        do
        {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }
    printf("探索したい数値を入力してください。");
    scanf("%d", &ky);

    int *idx = bsearch(&ky, x, nx, sizeof(int), (int (*)(const void *, const void *))int_cmp);

    if (idx == NULL)
        printf("探索に失敗しました。");
    else
        printf("%dはx[%d]に格納されています。", ky, (int)(idx - x));
    free(x);
    return 0;
}
