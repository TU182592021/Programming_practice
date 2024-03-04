#include <stdio.h>

// 各月の日数
int may_days[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
}; // may_days[行][列]

// 西暦yearは閏年か
int isleep(int year)
{
    return year % 4 == 0 && year % 100 != 00 || year % 400 == 0; // 当てはまったら1を当てはまらあなかったら0を変えす
}

// 西暦y年m月d日の経過日数を求める
int dayof_year(int y, int m, int d)
{
    int days = d;

    for (int i = 1; i < m; i++)
    {
        days += may_days[isleep(y)][i - 1];
    }
    return days;
}

int main(void)
{
    int retry;
    do
    {
        int year, month, day;
        printf("年は : ");
        scanf("%d", &year);
        printf("月は : ");
        scanf("%d", &month);
        printf("日にちは : ");
        scanf("%d", &day);

        printf("経過日数は%d日です。\n", dayof_year(year, month, day));
        printf("もう一度実行しますか？（はい1 / いいえ2） : ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}