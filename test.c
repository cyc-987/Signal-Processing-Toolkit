#include<stdio.h>
#include "signals.h"

int main()
{
    double a,b;
    a = 10;
    b = 30;
    long int seed = 13579;
    double result = uniform(a,b,&seed);
    printf("Random number between %lf and %lf is %lf\n",a,b,result);
    return 0;
}