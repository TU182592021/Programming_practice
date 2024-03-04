#ifndef ___IntStack
#define ___IntStack

typedef struct
{
    int max;
    int ptr;
    int *stk;
} IntStack;

int Initialize(IntStack *s, int max);

int push(IntStack *s, int x);

int pop(IntStack *s, int *x);

int peek(const IntStack *s, int *x);

void Clear(IntStack *s);

int capacity(const IntStack *s);

int size(const IntStack *s);

int isEmpty(const IntStack *s);

int isFull(const IntStack *s);

int Search(const IntStack *s, int x);

void Print(const IntStack *s);

void Terminate(IntStack *s);

#endif