//This file contains some functions to create signals
#include "signals.h"

double uniform(double a, double b, long int *seed)
//This function generates a random number between a and b
{
    double t;
    *seed = 2045 * (*seed) + 1;
    *seed = *seed - (*seed / 1048576) * 1048576;
    t = (double)(*seed) / 1048576.0;
    t = a + t * (b - a);
    return t;
}