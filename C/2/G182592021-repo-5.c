#include <stdio.h>
#include <string.h>

#define PI 3.141592653589793

void write_data(int, int);
double my_sin(double, int);
double my_cos(double, int);
double my_exp(double, int);

int main() {
  int num;
  int n;
  do {
    printf("------------------------------------\n");
    printf(" 1: sine 関数            \n");
    printf(" 2: cosine 関数          \n");
    printf(" 3: exponential 関数      \n");
    printf(" 4: 終了                 \n");
    printf("------------------------------------\n");
    scanf("%d", &num);
    if (1 <= num && num <= 3) {
      do {
        printf("何項までの和をもとめますか？(1以上)");
        scanf("%d", &n);
      } while (n <= 0);
      write_data(num, n);
    }
  } while (num != 4);
}

//近似値出力関数
void write_data(int type, int n) {
  double x_begin, x_end, x_step;
  double x, y;
  double rad;
  FILE *fp;
  char func_name[4], fname[256];
  switch (type) {
    case 1:  // sin
      strcpy(func_name, "sin");
      x_begin = 0;
      x_end = 365;
      x_step = 5;
      break;
    case 2:  // cos
      strcpy(func_name, "cos");
      x_begin = 0;
      x_end = 365;
      x_step = 5;
      break;
    case 3:  // exp
      strcpy(func_name, "exp");
      x_begin = -4.0;
      x_end = 4.0;
      x_step = 0.25;
      break;
  }
  sprintf(fname, "%s_n%d_data.csv", func_name, n);  //出力ファイル名の設定
  fp = fopen(fname, "w");  //出力ファイル名の設定
  fprintf(fp, "x,y\n");    //データラベルの入力

  //近似値の計算
  for (x = x_begin; x <= x_end; x += x_step) {
    switch (type) {
      case 1:
        // xをradに変換してmy_sinを呼び出す
        rad = x * PI / 180;
        y = my_sin(rad, n);
        break;
      case 2:
        // xをradに変換してmy_cosを呼び出す
        rad = x * PI / 180;
        y = my_cos(rad, n);
        break;
      case 3:
        y = my_exp(x, n);
        break;
    }
    fprintf(fp, "%f,%f\n", x, y);  //近似値データ出力
  }
  printf("%sのマクローリン展開　第%d項ま項の近似値を\n", func_name, n);
  printf("ファイル%sに出力しました\n", fname);
  fclose(fp);
}
// sin関数の近似値計算関数
double my_sin(double x, int n) {
  int i;
  double tmp, ans;
  tmp = x;
  ans = x;
  for (i = 1; i < n; i++) {
    tmp *= (-1) * x * x / ((2.0 * i) * (2.0 * i + 1.0));
    ans += tmp;
  }
  return ans;
}
// cos関数の近似値計算関数
double my_cos(double x, int n) {
  int i;
  double tmp, ans;
  tmp = 1.0;
  ans = 1.0;
  for (i = 1; i < n; ++i) {
    tmp *= (-1) * x * x / ((2.0 * i) * (2.0 * i - 1.0));
    ans += tmp;
  }
  return ans;
}
// exp関数の近似値計算関数
double my_exp(double x, int n) {
  int i;
  double ans, tmp;
  tmp = 1.0;
  ans = 1.0;
  for (i = 1; i < n; ++i) {
    tmp *= x / i;
    ans += tmp;
  }
  return ans;
}
