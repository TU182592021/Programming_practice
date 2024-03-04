#include <stdio.h>

int str_len(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

int str_chr(const char *s, int c)
{
    int i = 0;
    c = tolower((char)c);
    while (tolower(s[i]) != c)
    {
        if (s[i] == '\0')
            return -1;
        i++;
    }
    return i;
}

int str_cmp(const char *s1, const char *s2)
{
    while (tolower(*s1) == tolower(*s2))
    {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int main()
{
    char st1[100], st2[100], tmp[10];
    int ch, m, idx;

    while (1)
    {
        printf("(1) 文字列の長さ (2) 文字の探索 (3) 文字列の比較 (0) 終了: ");
        scanf("%d", &m);
        if (m == 0)
            break;

        printf("文字列を入力 : ");
        scanf("%s", st1);

        switch (m)
        {
        case 1:
            printf("その文字列は %d 文字です．\n", str_len(st1));
            break;
        case 2:
            printf("探索する文字： ");
            scanf("%s", tmp);
            ch = tmp[0];
            if ((idx = str_chr(st1, ch)) == -1)
                printf("存在しません\n");
            else
                printf("%d 文字目に存在します\n", idx + 1);
            break;
        case 3:
            printf("もう1つの文字列を入力 : ");
            scanf("%s", st2);
            if ((str_cmp(st1, st2)))
                printf("一致しません\n");
            else
                printf("一致しました\n");
            break;
        }
    }
    return 0;
}