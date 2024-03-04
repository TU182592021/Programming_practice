#include <stdio.h>
int main(void)
{
    int i, j;
    printf("-----------------九九の段-----------------\n");
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            printf(" %3d ", i * j);
        }
        printf("\n");
    }
}