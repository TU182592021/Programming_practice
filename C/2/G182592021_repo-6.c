#include <ctype.h> // 文 字 検 査 マ ク ロ を 使 用 す る た め
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 文 字 列 処 理 関 数 を 使 用 す る た め

#define WRDSIZE 20   // 単 語 の 最 大 文 字 数
#define TBLSIZE 1000 // 登 録 可 能 な 単 語 数
char word_table[TBLSIZE][WRDSIZE];

// プ ロ ト タ イ プ 宣 言
void count_word(int *, int *);
void sort_table(int *, int);
void print_table(int *, int);
int get_word(FILE *, char *, int);
void register_table(char *, int *, int *);

int main()
{
    int num_words = 0;
    int num_table[TBLSIZE];
    int i;
    // フ ロ ー チ ャ ー ト 参 照

    for (i = 0; i < TBLSIZE; ++i)
    {
        num_table[i] = 0;
    }
    count_word(&num_table[0], &num_words);
    print_table(&num_table[0], num_words);
}

void count_word(int *num_table, int *num_words)
{
    char tmp_word[WRDSIZE];
    FILE *fp;
    // フ ロ ー チ ャ ー ト 参 照
    fp = fopen("constitution_of_japan.txt", "r");
    if (fp == NULL)
    {
        printf("file not found.\n");
        exit(1);
    }
    while (EOF != get_word(fp, &tmp_word[0], WRDSIZE))
    {
        if (isalnum(tmp_word[0]))
        {
            register_table(&tmp_word[0], num_table, num_words);
        }
    }
    fclose(fp);
    return;
}

int get_word(FILE *fp, char *tmp_word, int limit)
{
    char *w = tmp_word;
    int c;
    // フ ロ ー チ ャ ー ト 参 照
    do
    {
        c = fgetc(fp);
    } while (isspace(c));
    if (c != EOF)
    {
        *w++ = c;
        if (isalnum(c))
        {
            for (; --limit > 1; ++w)
            {
                *w = fgetc(fp);
                if (isalnum(*w) == 0)
                {
                    break;
                }
            }
            *w = '\0';
            return tmp_word[0];
        }
    }
    return c;
}

void register_table(char *tmp_word, int *num_table, int *num_words)
{
    int n;
    // フ ロ ー チ ャ ー ト 参 照
    for (n = 0; n < *num_words; ++n)
    {
        if (strcmp(tmp_word, &word_table[n][0]) == 0)
        {
            num_table[n]++;
            return;
        }
    }
    strcpy(&word_table[*num_words][0], &tmp_word[0]);
    num_table[*num_words] = 1;
    *num_words += 1;
    return;
}

void sort_table(int *num_table, int num_words)
{
    int i, j, t;
    char tmp[WRDSIZE];
    // フ ロ ー チ ャ ー ト 参 照
    for (i = 0; i < num_words - 1; ++i)
    {
        for (j = i + 1; j < num_words; ++j)
        {
            if (strcmp(&word_table[i][0], &word_table[j][0]) > 0)
            {
                strcpy(tmp, &word_table[i][0]);
                strcpy(&word_table[i][0], &word_table[j][0]);
                strcpy(&word_table[j][0], tmp);
                t = num_table[i];
                num_table[i] = num_table[j];
                num_table[j] = t;
            }
        }
    }
    return;
}

void print_table(int *num_table, int num_words)
{
    int i, j; // word_table , n u m _ t a b l e の 内 容 を 表 示 す る 関 数
              // ， 自 分 で 考 え る
    for (j = 0; j < 74; ++j)
    {
        for (i = 0; i < num_words; ++i)
        {
            if (('0' + j) == word_table[i][0])
            {
                printf("%s: %d\n", &word_table[i][0], num_table[i]);
            }
        }
    }
}