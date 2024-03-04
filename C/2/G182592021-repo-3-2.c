#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//プロトタイプ宣言
void input(void);
void total(void);
void clac_statistics(void);
void print(void);
//グローバル関数
int score[10][6];
double average[6], stdev[6];
char person_name[10][20], subject_name[5][20];
int num_person;
int num_subjects;

int main() {
  input();
  total();
  clac_statistics();
  print();
}

void input(void) {
  int i, j;
  FILE *fp;
  if ((fp = fopen("report3.dat", "r")) == NULL) {
    printf("エラー終了");
    exit(1);
  }
  fscanf(fp, "%d", &num_subjects);
  printf("Number of subjects=%d\n", num_subjects);
  for (i = 0; i < num_subjects; i++) {
    fscanf(fp, "%s", &subject_name[i][0]);
  }

  num_person = 0;
  while (fscanf(fp, "%s", &person_name[num_person][0]) != EOF) {
    for (i = 0; i < num_subjects; i++) {
      fscanf(fp, "%d", &score[num_person][i]);
    }
    ++num_person;
  }
  fclose(fp);
  printf("Number of students=%d\n", num_person);
}

void total(void) {
  int i, j;
  for (i = 0; i < num_person; i++) {
    score[i][5] = 0;
    for (j = 0; j < num_subjects; j++) {
      score[i][5] += score[i][j];
    }
  }
}

void clac_statistics(void) {
  double sum, sqsum, t;
  int i, j;

  for (j = 0; j <= num_subjects; j++) {
    sum = 0;
    for (i = 0; i <= num_person; i++) {
      sum += score[i][j];
    }
    average[j] = sum / num_person;
  }
  for (j = 0; j <= num_subjects; ++j) {
    sqsum = 0.0;
    for (i = 0; i < num_person; i++) {
      t = score[i][j] - average[j];
      sqsum += t * t;
    }
    stdev[j] = sqrt(sqsum / num_person);
  }
}

void print(void) {
  printf("-----------------------------------------------------------------\n");
  printf("NAME      ");
  for (int i = 0; i < num_subjects; i++) {
    printf("%s   ", &subject_name[i][0]);
  }
  printf("total\n");

  for (int i = 0; i < num_person; i++) {
    printf("%-10s", &person_name[i][0]);
    for (int j = 0; j <= num_subjects; j++) {
      printf("%5d  ", score[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------------------------------------------------\n");
  printf("average    ");
  for (int i = 0; i < num_person; ++i) {
    printf("%5.1f", average[i]);
  }
  printf("\n");
  printf("stdev     ");
  for (int i = 0; i < num_person; ++i) {
    printf("%5.1f", stdev[i]);
  }
}