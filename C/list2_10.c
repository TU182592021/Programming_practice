#include <stdio.h>

int main(void)
{
    unsigned long counter;
    int prim[500];
    int ptr = 0;
    prim[ptr++] = 2;
    for (int n = 3; n <= 1000; n = n + 2)
    {
        int i;
        for (i = 1; i < ptr; i++)
        {
            counter++;
            if (n % prim[i] == 0)
                break;
        }
        if (ptr == i)
            prim[ptr++] = n;
    }
    for (int i = 0; i < ptr; i++)
        printf("%d\n", prim[i]);
    printf("除算回数は%luです。", counter);

    return 0;
}