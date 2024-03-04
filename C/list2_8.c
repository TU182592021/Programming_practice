#include <stdio.h>

// type型のxとyの値を変換
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0)

int card_conv(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQISTUVWXYZ";
    int digits = 0;

    if (x == 0)
    {
        d[digits++] = 0;
    }
    else
    {
        while (x)
        {
            d[digits++] = dchar[x % n]; // 先に代入されてからインクリメント++
            x /= n;                     // 先に割ってから代入
        }
        for (int i; i < digits; i++)
            swap(char, d[i], d[digits - i - 1]);

        return digits;
    }
}

int main(void)
{
    int retry;

    do
    {
        unsigned no;
        int cd;
        char cno[512];

        printf("変換する非負の値 : ");
        scanf("%u", &no); // unsigned型では%uを使う
        do
        {
            printf("何数に変換しますか？(2-32) : ");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 32);
        int dno = card_conv(no, cd, cno);
        printf("%d進数では", cd);
        for (int i = 0; i < dno; i++)
        {
            printf("%c", cno[i]); // char型は%cを使う
        }
        printf("です。\n");

        printf("もう一度実行しますか？(はい1 / いいえ2) : ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}