#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int hindo[26];
  char name[10];
  for (int i = 0; i < 26; ++i)
  {
    hindo[i] = 0;
    name[i] = 0;
  } //初期化

  FILE *fid = fopen(".\\foreword.txt", "r"); //ファイルを開く
  if (fid == NULL)
  {
    printf("file not found.\n");
    exit(1); //エラー終了
  }

  int c, A;
  while ((c = getc(fid)) != EOF)
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
  printf("名前を入力->");
  scanf("%s", &name[0]);
  for (A = 0; name[A] != '\0'; ++A)
  {
    printf("%c->%d\n", name[A], hindo[name[A] - 'a']);
  }
  fclose(fid);
}