gcc -c IntStack.h
gcc -c IntStack.c
gcc -c IntStacktest.c

gcc -o IntStacktest IntStacktest.o IntStack.o IntStack.o

IntStack.exe