#include <stdio.h>
#include <stdlib.h>
#include <time.h> //疑似乱数の生成のための必要

int maxof(const int a[], int n)
{
    int max = a[0];

    for (int i = 1; i <= n; i++)
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

    if (height == NULL)
    {
        printf("必要な領域が確保されていません\n");
    }
    else
    {
        srand(time(NULL)); // rand関数は種をもとに疑似乱数を生成するためその種を書き換えてあげる必要がある
        for (int i = 0; i < number; i++)
        {
            height[i] = 100 + rand() % 90;
            printf("height[%d] : %d\n", i, height[i]);
        }
    }
    printf("%d人の身長の最大値は%dです。", number, maxof(height, number));
    free(height);
    return 0;
}