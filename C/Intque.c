/*
    キューの実現例
*/

#include <stdio.h>
#include <stdlib.h>

/*--- キューを実現する構造体 ---*/
typedef struct
{
    int max;   /* キューのサイズ */
    int num;   /* 現在の要素数 */
    int front; /* 先頭要素カーソル */
    int rear;  /* 末尾要素カーソル */
    int *que;  /* キュー（の先頭要素へのポインタ） */
} IntQueue;

/*--- キューの初期化 ---*/
int Initialize(IntQueue *q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL)
    {
        q->max = 0; /* 配列の確保に失敗 */
        return (-1);
    }
    q->max = max;
    return (0);
}

/*--- キューの後始末 ---*/
void Terminate(IntQueue *q)
{
    if (q->que != NULL)
    {
        free(q->que); /* 配列を解放 */
        q->max = q->num = q->front = q->rear = 0;
    }
}

/*--- キューにデータをエンキュー ---*/
int Enque(IntQueue *q, int x)
{
    if (q->num >= q->max)
        return (-1); /* キューは満杯 */
    else
    {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return (0);
    }
}

/*--- キューからデータをデキュー ---*/
int Deque(IntQueue *q, int *x)
{
    if (q->num <= 0) /* キューは空 */
        return (-1);
    else
    {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return (0);
    }
}

/*--- キューの大きさ ---*/
int Capacity(const IntQueue *q)
{
    return (q->max);
}

/*--- キューに蓄えられているデータ数 ---*/
int Size(const IntQueue *q)
{
    return (q->num);
}

/*--- キューは空か ---*/
int IsEmpty(const IntQueue *q)
{
    return (q->num <= 0);
}

/*--- キューは満杯か ---*/
int IsFull(const IntQueue *q)
{
    return (q->num >= q->max);
}

void Show(const IntQueue *q)
{
    int i, j;
    printf("データ： ");
    for (i = 0, j = q->front; i < q->num; ++i)
    {
        printf("(%p) %d  ", &(q->que[j]), q->que[j]);
        ++j;
        if (j >= q->max)
            j = 0;
    }
    printf("\n");
}

int main(void)
{
    IntQueue que;

    if (Initialize(&que, 5) == -1)
    {
        puts("キューの確保に失敗しました。");
        return (1);
    }
    while (1)
    {
        int m, x;

        printf("現在のデータ数：%d/%d\n", Size(&que), Capacity(&que));
        printf("(1) エンキュー  (2) デキュー  (3)表示  (0) 終了：");
        scanf("%d", &m);

        if (m == 0)
            break;

        switch (m)
        {
        case 1:
            printf("データ：");
            scanf("%d", &x);
            if (Enque(&que, x) == -1)
                puts("データのエンキューに失敗しました。");
            break;

        case 2:
            if (Deque(&que, &x) == -1)
                puts("デキューできません。");
            else
                printf("デキューしたデータは%dです。\n", x);
            break;
        case 3:
            Show(&que);
            break;
        }
    }
    Terminate(&que);

    return (0);
}