//This file contains some functions to create signals
#include "signals.h"
#include<math.h>

double uniform(double a, double b, long int *seed)
{
    double t;
    *seed = 2045 * (*seed) + 1;
    *seed = *seed - (*seed / 1048576) * 1048576;
    t = (double)(*seed) / 1048576.0;
    t = a + t * (b - a);
    return t;
}

double gauss(double mean, double sigma, long int *seed)
{
    int i;
    double x, y;
    for(x=0,i=0;i<12;i++)
        x += uniform(0,1,seed);
    x -= 6.0;
    y = mean + sigma * x;
    return y;
}

double exponent(double beta, long int *seed)
{
    double t;
    t = uniform(0,1,seed);
    t = -beta * log(t);
    return t;
}

double laplace(double beta, long int *seed)
{
    double u1, u2, x;
    u1 = uniform(0,1,seed);
    u2 = uniform(0,1,seed);
    if(u1 < 0.5)
        x = -beta * log(1. - u2);
    else
        x = beta * log(u2);
    return x;
}

int bn(double p, long int *seed)
{
    double t;
    t = uniform(0,1,seed);
    if(t < p)
        return 1;
    else
        return 0;
}

int bin(int n, double p, long int *seed)
{
    int i;
    double x;
    for(x =0.0,i=0;i<n;i++)
        x += bn(p,seed);
    return x;
}

int poisson(double lambda, long int *seed)
{
    int i, x;
    double a, b, u;
    a = exp(-lambda);
    i = 0; b = 1.0;
    do{
        u = uniform(0,1,seed);
        b *= u;
        i++;
    }while(b >= a);
    x = i - 1;
    return x;
}

void sinwn(double a[], double f[], double ph[], int m, 
double fs, double snr, long seed, double x[], int n, int noiseOption)
{
    int i,k;
    double z,pi,nsr;
    pi = 4.0 * atan(1.0);
    z = snr / 10.0;
    z = pow(10.0,z);
    z = 1.0/(2*z);
    nsr = sqrt(z);
    if(noiseOption == 0)
        nsr = 0.0;

    for(i=0;i<m;i++)
    {
        f[i] = 2.0 * pi * f[i] / fs;
        ph[i] = ph[i] * pi / 180.0;
    }
    for(k=0;k<n;k++)
    {
        x[k] = 0.0;
        for(i=0;i<m;i++)
        {
            x[k] = x[k] + a[i] * sin(f[i] * k + ph[i]);
            x[k] = x[k] + nsr*gauss(0,1,&seed);
        }
    }
}