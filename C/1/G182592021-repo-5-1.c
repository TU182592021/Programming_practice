#include <math.h>
#include <stdio.h>
void equate();
int main() {
  equate();
  printf("もう一度行います。");
  equate();
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
    printf("実数解なし!");
  } else {
    printf("解は%d,%d", x1, x2);
  }
}