//このプログラムは簡単なRPGです。スライムを討伐することを目標としています。逃げることもできますが、成功するかは乱数次第です。
//また進行していくとプレイヤーとスライムそれぞれの状態が変わり、適当にボタンを押していると負けるようになっていますので、そこそこ考えないと勝てないようになっています。
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int menu1();
int menu2();
void A(void);
void B(void);
int i;
int main()
{
    int number;
    printf("町を出発!\nスライムが現れた!!\nどうする?→\n");
    do
    {
        switch (number = menu1())
        {
        case 1:
            A();
            break;
        case 2:
            B();
            break;
        default:
            printf("その選択はできない!\n");
            break;
        }
    } while ((number != 1 && number != 2) || (number == 2 && i == 0));
}
int menu1()
{
    int num;
    printf("----------------\n1.戦う\n2.逃げる\n----------------\n");
    scanf("%d", &num);
    return num;
}

void A(void)
{

    int number,
        EHP, HP, EA = 15, PA, care;
    for (EHP = 100, HP = 100; EHP > 0 && HP > 0;)
    {
        do
        {
            printf("スライム EHP %d\nPlayer HP %d\n", EHP, HP);
            switch (number = menu2())
            {
            case 1:
                if (EHP > 50)
                    PA = 5;
                else
                    PA = 15;
                printf("playerの物理攻撃!\nスライムに5のダメージ!\n");
                printf("EHP %d→%d\n", EHP, EHP - PA);
                EHP -= PA;
                if (EHP + PA > 50 && EHP <= 50)
                    printf("スライムの物理耐性減少!\nスライムの魔法耐性上昇!\nplayerの回復量減少!\n");
                break;
            case 2:
                if (EHP > 50)
                    PA = 10;
                else
                    PA = 5;
                printf("playerの魔法攻撃!\nスライムに10のダメージ!\n");
                printf("EHP %d→%d\n", EHP, EHP - PA);
                EHP -= PA;
                if (EHP + PA > 50 && EHP <= 50)
                    printf("スライムの物理耐性上昇!\nスライムの魔法耐性減少!\nplayerの回復量減少!\n");
                break;
            case 3:
                if (EHP > 50)
                    care = 25;
                else
                    care = 20;
                HP += care;
                printf("playerはHPを回復した!\nHP %d→%d\n", HP - care, HP);
                break;
            default:
                printf("その選択はできない!\n");
                break;
            }
        } while (number != 1 && number != 2 && number != 3);
        if (EHP <= 0)
        {
            printf("\nスライムを倒せた!\n");
            break;
        }
        printf("スライムの攻撃!\nplayerに%dダメージ!\n", EA);
        printf("HP %d→%d\n\n", HP, HP - EA);
        HP -= EA;
        if (HP <= 0)
        {
            printf("\nplayerは負けてしまった.....\n");
            break;
        }
    }
}
int menu2()
{
    int num;
    printf("\n------MENU------\n1.物理攻撃\n2.魔法攻撃\n3.回復\n----------------\n");
    scanf("%d", &num);
    return num;
}
void B(void)
{
    srand((unsigned int)time(NULL));
    int x, EHP, HP;
    int R = rand() % 2;
    printf("\n運試し! 数値を入力してください→");
    scanf("%d", &x);
    if (x % 2 == R)
    {
        printf("\n逃げれなかった\n");
        i = 0;
    }
    else
    {
        printf("逃げ切れた!\n町に戻った\n");
        i = 1;
    }
}
