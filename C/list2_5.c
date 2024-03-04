#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n) // constは値の書きこみを不可能にする。実引数から仮引数へは、要素数は渡されないためnとして渡す。
{
    int max = a[0];

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int main(void)
{
    int number;

    printf("人数は？->");
    scanf("%d", &number);

    int *height = calloc(number, sizeof(int));

    printf("%d人の身長を入力してください。\n", number);
    for (int i = 0; i < number; i++)
    {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }
    printf("%d人の最大値は%dです。", number, maxof(height, number));
    int list[] = [ 90, 180, 22 ];
    double BMI = 10000 * list[0] / list[1] / list[1];
    printf("%s", BMI);
    free(height);
    return 0;
}