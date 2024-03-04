#include <math.h>
#include <stdio.h>
int menu(void);
void rute(void);
void up(void);
void it(void);
double f(double);

int main()
{
  int number;
  do
  {
    switch (number = menu())
    {
    case 1:
      rute();
      break;
    case 2:
      up();
      break;
    case 3:
      it();
      break;
    case 4:
      printf("処理を終了します");
      break;
    default:
      printf("入力エラーです");
      break;
    }
  } while (number != 4);
}

int menu(void)
{
  int num;
  printf(
      "--------Menu---------\n1. "
      "平方根の近似計算\n2.　ボール投げ\n3.　台形則による積分\n4. "
      "終了\n------------------------\n処理番号を入力してください→");
  scanf("%d", &num);
  return num;
}
void rute(void)
{
  double x, r0, rk, rk1;
  int n, i;
  printf("平方根の近似値を求めます。√の中身を入力してください。→");
  scanf("%lf", &x);
  printf("どこまで計算しますか？→");
  scanf("%d", &n);
  r0 = 1.0;
  rk1 = r0;
  for (i = 1; i <= n; i++)
  {
    rk = (rk1 + x / rk1) / 2;
    printf("r%d        %11.8f\n", i, rk);
    rk1 = rk;
  }
  printf("標準関数sqrt(%lf,0)の値%11.8f\n", x, rk);
}
void up(void)
{
  double v, p, h, d, r, g, i, pi;
  printf(
      "初速度 "
      "vで，地面に対して角度θ°でボールを投げたときの最高点の高さ,"
      "および到達距離を求めます。ボールを投げる初速度v(m/sec)→");
  scanf("%lf", &v);
  printf("投げ始める高さを入力してくださいh(m)");
  scanf("%lf", &p);
  g = 9.8;
  i = 0;
  pi = 3.14159;
  printf("角度  最高到達点  到達距離\n----------------------------\n");
  for (i = 0; i <= 90; i += 5)
  {
    r = i * pi / 180;
    h = (v * v * sin(r) * sin(r)) / (2 * g) + p;
    d = (v * cos(r) *
         (v * sin(r) + sqrt(v * v * sin(r) * sin(r) + 2 * g * p))) /
        g;
    printf("%lf° 　%lfm   %lfm\n", i, h, d);
  }
}
double f(double x)
{
  double y;
  y = sqrt(4 - x * x);
  return y;
}
void it(void)
{
  double a, b, s, h;
  int m, n;
  printf("積分区間a,b→");
  scanf("%lf%lf", &a, &b);
  printf("ab間の分割数m→");
  scanf("%d", &m);
  h = (b - a) / m;
  s = 0;
  for (n = 0; n < m; ++n)
  {
    s += (f(a + n * h) + f(a + (n + 1) * h)) * h / 2;
  }
  printf("積分値　Ｓ＝%f\n", s);
}