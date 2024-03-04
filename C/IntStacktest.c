#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;
    if (Initialize(&s, 64) == -1)
    {
        puts("スタックの生成に失敗しました。");
        return 1;
    }
    while (1)
    {
        int menu, x;
        printf("現在のデータ数 : %d/%d", size(&s), capacity(&s));
        printf("(1)プッシュ (2)ポップ (3)ピーク (4)表示 (0)終了");
        scanf("%d", &menu);
        if (menu == 0)
            break;
        switch (menu)
        {
        case 1:
            printf("データ");
            scanf("%d", &x);
            if (push(&s, x) == -1)
                puts("エラー : プッシュに失敗しました。");
            break;
        case 2:
            if (pop(&s, &x) == -1)
                puts("エラー : ポップに失敗しました。");
            else
                printf("ポップしたデータは%dです。", x);
            break;
        case 3:
            if (peek(&s, &x) == -1)
                puts("エラー : ピークに失敗しました。");
            else
                printf("ピークしたデータは%dです。", x);
            break;
        case 4:
            Print(&s);
            break;
        }
    }
    Terminate(&s);
    return 0;
}