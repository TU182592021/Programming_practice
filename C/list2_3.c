// calloc関数、malloc関数、free関数
#include <stdio.h>
#include <stdlib.h> //calloc関数、malloc関数、free関数を使うために必要

int main(void)
{
    int *x = calloc(1, sizeof(int)); // １つの配列を作る
    if (x == NULL)
    {
        printf("必要な領域を確保できませんでした。");
    }
    else
    {
        *x = 57;
        printf("%d", *x);
        free(x); // 領域の開放
    }
    return 0;
}