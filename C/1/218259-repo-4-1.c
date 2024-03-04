#include <stdio.h>
int main(void)
{
    int i;
    int num, max, min;

    for (i = 0; i < 10; i++)
    {
        printf("数値を入力してください→");
        scanf("%d", &num);
        if (i == 0)
        {
            max = num;
            min = num;
        }
        if (max < num)
            max = num;
        if (min > num)
            min = num;
    }
    printf("最大値=%d 最小値=%d", max, min);
}
