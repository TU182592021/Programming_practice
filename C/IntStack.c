#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

// ptr スタックポインタ(実際に入っている個数)
// max スタックの容量
//*stk スタック本体
//*がつくときは書き換え、つかないときはコピーを扱う

int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if (s->ptr = calloc(max, sizeof(int)) == NULL)
    {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int push(IntStack *s, int x)
{
    if (s->ptr >= s->max)
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

int pop(IntStack *s, int *x)
{
    if (s->ptr == 0)
        return -1;
    *x = s->stk[s->ptr--];
    return 0;
}

int peek(const IntStack *s, int *x)
{
    if (s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

void Clear(IntStack *s)
{
    s->ptr = 0;
}

int capacity(const IntStack *s)
{
    return s->max;
}

int Size(const IntStack *s)
{
    return s->ptr;
}

int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0;
}

int isFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

int serch(const IntStack *s, int *x)
{
    {
        for (int i = s->ptr - 1; i >= 0; i--)
            if (s->stk[i] == x)
                return i;
    }
    return -1;
}

void Print(const IntStack *s)
{
    for (int i = 0; i < s->ptr; i++)

        printf("%d", s->stk[i]);

    putchar('\n');
}

void Terminate(IntStack *s)
{
    if (s->stk != NULL)

        free(s->stk);
    s->max = s->ptr = 0;
}