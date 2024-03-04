/* 力まかせ法による文字列探索 */

#include <stdio.h>

///////////////////////////////////////////////
#include <string.h> /////
//////////////////////////////////////////////

/*--- 力まかせ法による文字列探索 ---*/
int bf_match(const char txt[], const char pat[])
{
    ///////////////////////////////////////
    int i, k = -1;
    int count = 0;
    int tlen = strlen(txt);
    int plen = strlen(pat);
    //////////////////////////////////////

    int pt = 0; /* txtをなぞるカーソル */
    int pp = 0; /* patをなぞるカーソル */

    while (txt[pt] != '\0' && pat[pp] != '\0')
    {

        ///////////////////////////////////////////
        if (k == pt - pp)
            printf("    ");
        else
            printf("%2d  ", k = pt - pp);

        for (i = 0; i < tlen; i++)
            printf("%c", txt[i]);
        printf("\n");

        printf("%*s%c\n", pt + 4, "", (txt[pt] == pat[pp]) ? 'o' : 'x');
        printf("%*s", (pt - pp) + 4, "");
        for (i = 0; i < plen; i++)
            printf("%c", pat[i]);
        printf("\n\n");
        count++;
        //////////////////////////////////////////

        if (txt[pt] == pat[pp])
        {
            pt++;
            pp++;
        }
        else
        {
            pt = pt - pp + 1;
            pp = 0;
        }
    }

    ///////////////////////////////////////////////
    printf("比較は%d回でした。\n", count);
    ///////////////////////////////////////////////

    if (pat[pp] == '\0')
        return pt - pp;
    return -1;
}

int main(void)
{
    int idx;
    char s1[256]; /* テキスト */
    char s2[256]; /* パターン */

    puts("力まかせ法");

    printf("テキスト：");
    scanf("%s", s1);

    printf("パターン：");
    scanf("%s", s2);

    idx = bf_match(s1, s2); /* 文字列s1から文字列s2を力まかせ法で探索 */

    if (idx == -1)
        puts("テキスト中にパターンは存在しません。");
    else
        printf("%d文字目にマッチします。\n", idx + 1);

    return 0;
}