#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "read_pgm.h"
int main()
{
    int w0, w1, h0, h1, m0, m1;
    unsigned char *M = read_pgm("p0_01.pgm", &w0, &h0, &m0);
    unsigned char *N = read_pgm("p0_01_ht.pgm", &w1, &h1, &m1);
    int i, j;
    double MSEbunsi = 0, MSEbunbo = 0, PSMR = 0, MSE = 0;

    printf("width=%d,height=%d,maxval=%d\n", w0, h0, m0);
    MSEbunbo = w0 * h0;
    for (i = 0; i < h0; ++i)
    {
        for (j = 0; j < w0; ++j)
        {
            MSEbunsi += (M[i * w0 + j] - N[i * w1 + j]) * (M[i * w0 + j] - N[i * w1 + j]);
        }
    }

    MSE = MSEbunsi / MSEbunbo;
    PSMR = 10 * log10((m0 * m0) / MSE);
    printf("MSE値は、%lf\n", MSE);
    printf("p0_01.pgnに対するp0_01_ht.pgmのPSMR値は、%lfである。\n", PSMR);
}