#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int hindo[26];
  for (int i = 0; i < 26; ++i)
  {
    hindo[i] = 0;
  } //初期化

  FILE *fp = fopen(".\\foreword.txt", "r"); //ファイルを開く
  if (fp == NULL)
  {
    printf("file not found.\n");
    exit(1); //エラー終了
  }

  int c;
  while ((c = getc(fp)) != EOF)
  {
    if (isalpha(c))
    {
      if (islower(c))
      {
        ++hindo[c - 'a'];
      }
      else
      {
        ++hindo[c - 'A'];
      } //分別化
    }
  }
  for (int i = 0; i < 26; ++i)
  {
    printf("%c -> %d\n", i + 'a', hindo[i]);

  } //書き出し
  fclose(fp);
}