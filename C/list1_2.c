#include <stdio.h>

int max3(int a, int b, int c)
{
    int max;
    max = a;
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    return max;
}

int main(void)
{
    printf("max3(%d, %d, %d) = %d\n", 3, 2, 1, max3(3, 2, 1));
    printf("max3(%d, %d, %d) = %d\n", 2, 3, 1, max3(2, 3, 1));
    printf("max3(%d, %d, %d) = %d\n", 2, 1, 3, max3(2, 1, 3));
    return 0;
}