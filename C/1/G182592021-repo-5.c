#include <math.h>
#include <stdio.h>
void equate();
void box();
void rank();
int main() {
  equate();
  printf("もう一度行います。");
  equate();
  box();
  rank();
}
void equate() {
  int a, b, c, D, x1, x2;
  printf("aX^2+bx+cの関数の解を求めます。数値を入力してください。\na→");
  scanf("%d", &a);
  printf("b→");
  scanf("%d", &b);
  printf("c→");
  scanf("%d", &c);
  printf("a=%d b=%d C=%d", a, b, c);
  D = b * b - 4 * a * c;
  x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
  x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
  if (D < 0) {
    printf("実数解なし!\n");
  } else {
    printf("解は%d,%d\n", x1, x2);
  }
}
void box() {
  int a, b, i, V, maxv;
  printf(
      "2辺の長さがa,b(cm)である長方形段ボールの4隅をx(cm)"
      "切り取ってできる体積を求めます。数値を入力してください。\na→");
  scanf("%d", &a);
  printf("b→");
  scanf("%d", &b);
  if (a > 0 && b > 0) {
    for (i = 1;; i++) {
      if ((a - 2 * i) > 0 && (b - 2 * i) > 0) {
        V = (a - 2 * i) * (b - 2 * i) * i;
        printf("四隅を%dcm切り取ったときにできる体積は%dcm^3です。\n", i, V);
      } else {
        printf("これ以上は存在しません");
        break;
      }
    }
  } else {
    printf("このような物体は存在しません");
  }
}
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
      "人です。\nCランクは%d人です。\nDランクは%d人です。\n平均点は%d点",
      A, B, C, D, S);
}