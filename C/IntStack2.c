/*
    スタックの実現例
*/

#include <stdio.h>
#include <stdlib.h>

/*--- スタックを実現する構造体 ---*/
typedef struct
{
    int max;  /* スタックのサイズ */
    int ptr;  /* スタックポインタ */
    int *stk; /* スタック（の先頭要素へのポインタ） */
} IntStack;

/*--- スタックの初期化 ---*/
int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = (int *)calloc(max, sizeof(int))) == NULL)
    {
        s->max = 0; /* 配列の確保に失敗 */
        return (-1);
    }
    s->max = max;
    return (0);
}

/*--- スタックの後始末 ---*/
void Terminate(IntStack *s)
{
    if (s->stk != NULL)
    {
        free(s->stk);
        s->max = s->ptr = 0;
    }
}

/*--- スタックにデータをプッシュ ---*/
int Push(IntStack *s, int x)
{
    if (s->ptr >= s->max)
        return (-1);
    s->stk[s->ptr++] = x;
    return (0);
}

/*--- スタックからデータをポップ ---*/
int Pop(IntStack *s, int *x)
{
    if (s->ptr <= 0) /* スタックは空 */
        return (-1);
    *x = s->stk[--s->ptr];
    return (0);
}

/*--- スタックからデータをピーク ---*/
int Peek(const IntStack *s, int *x)
{
    if (s->ptr <= 0) /* スタックは空 */
        return (-1);
    *x = s->stk[s->ptr - 1];
    return (0);
}

/*--- スタックの大きさ ---*/
int Capacity(const IntStack *s)
{
    return (s->max);
}

/*--- スタックに積まれているデータ数 ---*/
int Size(const IntStack *s)
{
    return (s->ptr);
}

/*--- スタックは空か ---*/
int IsEmpty(const IntStack *s)
{
    return (s->ptr <= 0);
}

/*--- スタックは満杯か ---*/
int IsFull(const IntStack *s)
{
    return (s->ptr >= s->max);
}

/*--- スタックを空にする ---*/
void Clear(IntStack *s)
{
    s->ptr = 0;
}

void Show(const IntStack *s)
{
    int i;
    printf("データ： ");
    for (i = 0; i < s->ptr; ++i)
    {
        printf("(%p) %d  ", &(s->stk[i]), s->stk[i]);
    }
    printf("\n");
}

int main(void)
{
    IntStack s;

    if (Initialize(&s, 5) == -1)
    {
        puts("スタックの確保に失敗しました。");
        return (1);
    }
    while (1)
    {
        int m, x;

        printf("現在のデータ数：%d/%d\n", Size(&s), Capacity(&s));
        printf("(1) プッシュ  (2) ポップ (3)表示 (0) 終了：");
        scanf("%d", &m);

        if (m == 0)
            break;

        switch (m)
        {
        case 1:
            printf("データ：");
            scanf("%d", &x);
            if (Push(&s, x) == -1)
                puts("スタックへのプッシュに失敗しました。");
            break;

        case 2:
            if (Pop(&s, &x) == -1)
                puts("ポップできません。");
            else
                printf("ポップしたデータは%dです。\n", x);
            break;
        case 3:
            Show(&s);
            break;
        }
    }
    Terminate(&s);

    return (0);
}