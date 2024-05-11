#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "signals.h"


int main()
{
    srand(time(NULL));//seed for random number generator
    
    long int seed = rand();
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%10d ",poisson(7,&seed));
        }
        printf("\n");
    }
    return 0;
}