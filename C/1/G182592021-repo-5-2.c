#include <stdio.h>
void box();
int main() { box(); }
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