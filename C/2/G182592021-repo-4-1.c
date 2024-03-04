#include <stdio.h>

int menu(void);
void kuku10(void);
void kuku(int);

int main() {
  int num;

  do {
    num = menu();
    if (num == 0) {
      printf("終了します\n");
    } else if (num == 10) {
      kuku10();
    } else if (3 <= num && num <= 16) {
      kuku(num);
    } else {
      printf("表示できるのは3進数16進数までです\n");
    }
  } while (num != 0);
}

int menu(void) {
  int n;
  printf("何進数の掛け算表を出力しますか?(0で終了):");
  scanf("%d", &n);
  return n;
}

void kuku10(void) {
  int a, i, j;

  printf(" |");
  for (i = 1; i <= 9; ++i) {
    printf("  %d", i);
  }
  printf("\n");
  printf("---------------------------------\n");
  for (j = 1; j <= 9; ++j) {
    printf("%d |", j);
    for (a = 1; a <= 9; ++a) {
      printf("%4d", j * a);
    }
    printf("\n");
  }
}

void kuku(int num) {
  char n[] = "0123456789ABCDEF";
  int a, i;

  printf(" |");
  for (i = 1; i < num; ++i) {
    printf("  %c", n[i]);
  }
  printf("\n");
  for (i = 0; i < num; i++) {
    printf("-------");
  }
  printf("\n");
  for (i = 1; i < num; ++i) {
    printf("%c |", n[i]);
    for (a = 1; a < num; ++a) {
      printf(" %c%c", n[i * a / num], n[i * a % num]);
    }
    printf("\n");
  }
}
