#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "signals.h"
#include "dsp.h"


int main()
{
    srand(time(NULL)); // seed for random number generator

    /*
    long int seed = rand();
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%10d ",poisson(7,&seed));
        }
        printf("\n");
    }
    */
    double a[] = {1.0, 2.0};
    double f[] = {50.0, 60.0};
    double ph[] = {0.0,90};
    int m = 2;
    double fs = 1000.0;
    double snr = 0;
    long seed = 1;
    double x[1000];
    int n = 1000;
    sinwn(a, f, ph, m, fs, snr, seed, x, n, 0);

    double y[1000] = {0};
    double a1[1000] = {0};
    double b1[1000] = {0};
    dft(x, y, a1, b1, n);
    //write to file
    FILE *file = fopen("testOutput.csv", "w");
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%f\n",sqrt(a1[i]*a1[i]+b1[i]*b1[i]));
    }
    fclose(file);
    return 0;
}