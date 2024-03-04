#include <stdio.h>

int main(void)
{
    int n;
    printf("整数->");
    scanf("%d", &n);
    if (n >= 10)
    {
        if (n >= 100)
        {
            if (n >= 100)
            {
                if (n >= 1000)
                {
                    if (n >= 10000)
                    {
                        printf("桁数は5");
                    }
                    else
                        printf("桁数は4");
                }
                else
                    printf("桁数は3");
            }
            else
                printf("桁数は3");
        }
        else
            printf("桁数は2");
    }
    else
        printf("桁数は1");

    return 0;
}