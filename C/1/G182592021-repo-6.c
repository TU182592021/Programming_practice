#include <stdio.h>
int menu(void);
void Roher(void);
void leapyear(void);
void fibo(void);

int main()
{
    int number;

    do
    {
        switch (number = menu())
        {
        case 1:
            Roher();
            break;
        case 2:
            leapyear();
            break;
        case 3:
            fibo();
            break;
        case 4:
            printf("処理を終了します。\n");
            break;
        default:
            printf("入力エラーです\n");
            break;
        }
    } while (number != 4);
}
int menu(void)
{
    int num;
    printf("-------menu--------\n 1. ローレル指数\n 2. うるう年\n 3. フィボナッチ数列\n 4. 終了\n ----------------\n\n");
    printf("番号を選んでください。→");
    scanf("%d", &num);
    return num;
}
void Roher(void)
{
    double h, w, R;
    printf("身長を入力→");
    scanf("%lf", &h);
    printf("体重を入力→");
    scanf("%lf", &w);
    R = w * 10.0 / h * h * h;
    printf("あなたのローレル指数は%5.1fです。", R);
    if (R < 100)
    {
        printf("瘦せすぎです。");
    }
    else if (R > 100 && R < 115)
    {
        printf("痩せています。");
    }
    else if (R > 115 && R < 145)
    {
        printf("標準です。");
    }
    else if (R > 145 && R < 159)
    {
        printf("太っています。");
    }
    else
    {
        printf("太りすぎです。");
    }
}
void leapyear(void)
{
    int y;
    printf("調べたい年を入力してください。→");
    scanf("%d", &y);
    if (y % 400 == 0)
    {
        printf("%d年はうるう年です。", y);
    }
    else if (y % 4 == 0 && y % 100 != 0)
    {
        printf("%d年はうるう年です。", y);
    }
    else
    {
        printf("%d年は並年です。", y);
    }
}
void fibo(void)
{
    int k, i;
    int fk, fk1, fk2;
    printf("数値を入力してください→");
    scanf("%d", &k);
    fk1 = 1;
    fk2 = 1;
    printf("f0の値→ 1\nf1の値→ 1\n");
    for (i = 2; i - 1 > k; i++)
    {
        fk = fk1 + fk2;
        printf("f%dの値→%d", i, fk);
        fk2 = fk1;
        fk1 = fk;
    }
}