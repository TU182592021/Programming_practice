#include <stdio.h>
int main()
{
    int a, b, c, d, e;
    printf("    |");
    for (a = 1; a < 10; a++)
        printf("%3d", a);
    printf("\n");
    printf("----+");
    for (b = 1; b <= 9; b++)
        printf("-----");
    printf("\n");
    for (c = 1; c < 10; c++)
    {
        printf("%d   |", c);
        for (d = 1; d < 10; d++)
        {
            printf("%3d", c * d);
        }
        printf("\n");
    }
}