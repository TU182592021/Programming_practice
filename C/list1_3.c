// 値の正、負、0を判定する

#include <stdio.h>

int main(void)
{
    int n;

    printf("好きな数値を入れてください->");
    scanf("%d", &n);
    if (n > 0)
        printf("数値は正の値です。");
    else if (n < 0)
        printf("数値は負の値です。");
    else
        printf(" 値は0です。");
}