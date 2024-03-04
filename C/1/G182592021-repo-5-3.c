#include <stdio.h>
void rank();
int main() { rank(); }
void rank() {
  int x, i, S, A, B, C, D;
  A = 0;
  B = 0;
  C = 0;
  D = 0;
  for (i = 1; i < 21; i++) {
    printf("%d人目の点数→", i);
    scanf("%d", &x);
    if (x >= 80) {
      A += 1;
    } else if (x >= 60 && x < 80) {
      B += 1;
    } else if (x >= 50 && x < 60) {
      C += 1;
    } else {
      D += 1;
    }
    S += x;
  }
  S = S / 20;
  printf(
      "--------------------------\nAランクは%d人です。\nBランクは%d"
      "人です。\nCランクは%d人です。\nDランクは%d人です。平均点は%d点",
      A, B, C, D, S);
}