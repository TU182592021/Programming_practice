///////////////////////////////////////////////////////////////////////////////////
// ２分探索木のサンプルプログラム
// ノードの追加およびノードの削除が可能
// ノードの構造体用に，TNODE型を定義
///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/* tree node */
typedef struct tnode
{
    struct tnode *left;
    int num;
    struct tnode *right;
} TNODE;

/* prototype */
TNODE *addnode(TNODE *, int);
TNODE **search(TNODE **, int);
void delnode(TNODE **);
void printtree(TNODE *, int);

void main()
{
    TNODE *root = NULL, **ppt;
    int n, i, j;
    while (1)
    {
        printf("数値を入力: ");
        scanf("%d", &n);
        if (n == 0)
            break;
        if (n > 0)
        {
            printf("**** データの追加****\n");
            printf("%dをノードに追加します\n\n", n);
            root = addnode(root, n);
            printtree(root, 6);
        }
        else if (n < 0)
        {
            printf("**** データの削除****\n");
            j = abs(n);
            n = j;
            printf("%dをノードから削除します。\n\n", n);
            ppt = search(&root, n);
            delnode(ppt);
            printtree(root, 6);
        }
    }
}

TNODE *addnode(TNODE *p, int key)
{
    if (p == NULL)
    {
        p = (TNODE *)malloc(sizeof(TNODE));
        p->num = key;
        p->right = p->left = NULL;
    }
    else
    {
        if (key < p->num)
            p->left = addnode(p->left, key);
        else
            p->right = addnode(p->right, key);
    }
    return p;
}

TNODE **search(TNODE **pp, int key)
{
    while (*pp != NULL && key != (*pp)->num)
    {
        if (key < (*pp)->num)
        {
            pp = &(*pp)->left;
        }
        else
        {
            pp = &(*pp)->right;
        }
    }
    return pp;
}

void delnode(TNODE **pp)
{
    TNODE *p, **qq, *q;

    if (*pp != NULL)
    {
        p = *pp;
        if (p->right == NULL)
        {
            *pp = p->left;
            free(p);
        }
        else if (p->left == NULL)
        {
            *pp = p->right;
            free(p);
        }
        else
        {
            qq = &p->left;
            while ((*qq)->right != NULL)
            {
                qq = &(*qq)->right;
            }
            q = *qq;
            *qq = q->left;
            p->num = q->num;
            free(q);
        }
    }
}

void printtree(TNODE *p, int pos)
{
    if (p != NULL)
    {
        printtree(p->right, pos + 6);
        printf("%*d \n", pos, p->num);
        // pos はフィールド幅を与える。
        printtree(p->left, pos + 6);
    }
}