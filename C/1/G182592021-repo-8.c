#include <stdio.h>

int menu(void);
void ave(void);
void rank(void);
void sinsuu(void);

int main()
{
    int number;

    do
    {
        switch (number = menu())
        {
        case 1:
            ave();
            break;
        case 2:
            rank();
            break;
        case 3:
            sinsuu();
            break;
        case 4:
            printf("処理を終了します\n");
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

    printf("-------- menu -------\n");
    printf(" 1. テストの成績（平均・分散）\n");
    printf(" 2. テストの成績（ランク・ヒストグラム）\n");
    printf(" 3. 10進数を2進数に変換\n");
    printf(" 4. 終 了\n");
    printf("---------------------\n\n");
    printf("番号を選んで下さい→ ");
    scanf("%d", &num);
    return num;
}

void ave(void)
{
    int ten[100], i, N = 10, n, sum;
    double ave, var, A, B;

    for (i = 0; i < 100; ++i)
    {
        ten[i] = 0;
    }

    for (n = 0; n < N; ++n)
    {
        printf("%d人目の点数は？: ", n + 1);
        scanf("%d", &ten[n]);
    }

    sum = 0;
    for (n = 0; n < N; ++n)
    {
        sum = sum + ten[n];
    }

    ave = sum / N;

    A = 0;
    for (n = 0; n < N; ++n)
    {
        A = A + (ten[n] - ave) * (ten[n] - ave);
    }

    B = A / N;

    printf("%d人の点数の平均は %lf 分散は %lf です\n", N, ave, B);
}

void rank(void)
{
    int ten, i, histo[11], n;

    for (i = 0; i <= 10; ++i)
    {
        histo[i] = 0;
    }

    for (i = 0; i < 10; ++i)
    {
        printf("%d人目の点数は?", i + 1);
        scanf("%d", &ten);
        ++histo[ten / 10];
    }

    for (i = 0; i <= 10; ++i)
    {
        printf("ランク %2d: %2d 人 ", i, histo[i]);

        for (n = 0; n < histo[i]; ++n)
        {
            printf("*");
        }

        printf("\n");
    }

    printf("\n");
}

void sinsuu(void)
{
    int num10, num2, base;

    do
    {
        printf("0から225の数字を入力してください→");
        scanf("%d", &num10);
    } while (num10 < 0 || 225 < num10);

    base = 1;
    num2 = 0;
    while (num10 > 0)
    {
        num2 = num2 + (num10 % 2) * base;
        num10 = num10 / 2;
        base = base * 10;
    }
    printf("10進数の%dは、2進数の%dです\n", num10, num2);
}