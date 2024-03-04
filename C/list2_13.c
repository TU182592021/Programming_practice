#include <stdio.h>

struct xyz // 構造体xyz型の宣言
{
    int x;
    long y;
    double z;
};

// struct xyz a; //struct xyz型のaという配列を作る
// struct xyz *p = &a; //sturct xyz型のポインタpにaのアドレスを格納
typedef struct xyz XYZ; // sturct xyz型に新しい名前を与える(打ちやすいように)

XYZ a;       // 中の情報にアクセスするにはa.x,a.y,a.zと書く(ポインタ演算子.)
XYZ *p = &a; // ポインタの情報にアクセスするにはp->x,p->y,p->zと書く(アロー演算子->)
