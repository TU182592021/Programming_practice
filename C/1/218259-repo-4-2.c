#include <stdio.h>
int main()
{
    int num, a;
    printf("数値を入力してください");
    scanf("%d", &num);
    for (a = 2; a * a <= num;)
    {
        if (num % a == 0)
        {
            printf("%d*", a);
            num = num / a;
        }
        else
        {
            a = a + 1;
        }
    }
    printf("%d", num);
}
