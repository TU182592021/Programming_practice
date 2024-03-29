/************************************/
/*  プログラミング演習レポート＃00  */
/* 【 ここにレポートの題目を書く 】 */
/*                  学籍番号：00000 */
/*                 作成者：拓殖太郎 */
/*               作成日：2013/05/28 */
/************************************/

#include <stdio.h>

void hanoi(int, int, int, int);
int num;

void main()
{
    int n;

    printf("円盤の数 ： ");
    scanf("%d", &n);

    num = 0;
    hanoi(n, 1, 3, 2);
}

// ハノイの塔を移動する関数．
// n個の円盤をaからbへ（cを使って）移動する．
void hanoi(int n, int a, int b, int c)
{
    if (n == 1)
        printf("%3d回目 %d → %d\n", ++num, a, b);
    else
    {
        ********************** // n-1個の円盤を aからcへ移動する．
                             printf("%3d回目 %d → %d\n", ++num, a, b);
        ********************** // n-1個の円盤を cからbへ移動する．
    }
}