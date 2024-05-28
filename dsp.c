#include<math.h>
#include "dsp.h"

void dft(double x[], double y[], double a[], double b[], int n)
{
    int i, k;
    double c, d, q, w, s;
    q = 2.0*PI/n;

    for(k=0;k<n;k++)
    {
        w = q*k;
        a[k] = b[k] = 0.0;
        for(i=0;i<n;i++)
        {
            d = i*w;
            c = cos(d);
            s = sin(d);
            a[k] += x[i]*c + y[i]*s;
            b[k] += y[i]*c - x[i]*s;
        }
    }
}