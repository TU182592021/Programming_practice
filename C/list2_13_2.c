#include <stdio.h>

#define VMAX 21

/*身体検査データ型*/
typedef struct
{
    char name[20];
    int height;
    double vision;
} physcheck;

double ave_height(physcheck dat[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += dat[i].height;
    }
    sum /= n;
    return sum;
}

void dist_vision(const physcheck dat[], int n, int dist[])
{
    for (int i = 0; i < VMAX; i++)
        dist[i] = 0;
    for (int i = 0; i < n; i++)
    {
        if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
            dist[(int)(dat[i].vision * 10)]++;
    }
}

int main(void)
{
    physcheck x[] = {
        {"Yudai", 166, 0.8},
        {"House", 180, 0.5},
        {"Hanawin", 175, 0.8},
        {"Yuya", 167, 0.5},
        {"Kazuki", 163, 0.6},
        {"Hinaiji", 170, 1.0},
    };

    int nx = sizeof(x) / sizeof(x[0]);
    int vdisit[VMAX];

    printf("   身体検査一覧表   \n");
    puts(" 氏名              身長 視力");
    puts("-------------------------------");

    for (int i = 0; i < nx; i++)
    {
        printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
    }
    printf("\n平均身長 : %5.1fcm\n", ave_height(x, nx));
    dist_vision(x, nx, vdisit);
    printf("\n視力の分布\n");
    for (int i = 0; i < VMAX; i++)
        printf("%3.1f～ :%2d人\n", i / 10.0, vdisit[i]);

    return 0;
}