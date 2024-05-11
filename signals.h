#ifndef _SIGNALS_H_
#define _SIGNALS_H_

double uniform(double a, double b, long int *seed);
//This function generates a random number between a and b
//平均分布
double gauss(double mean, double sigma, long int *seed);
//This function generates a random number from a Gaussian distribution 
//with mean mean and standard deviation sigma
//高斯分布
double exponent(double beta, long int *seed);
//This function generates a random number from an exponential distribution
//指数分布
double laplace(double beta, long int *seed);
//This function generates a random number from a Laplace distribution
//拉普拉斯分布
int bn(double p, long int *seed);
//This function generates a random number from a Bernoulli distribution
//伯努利分布
int bin(int n, double p, long int *seed);
//This function generates a random number from a binomial distribution
//二项分布
int poisson(double lambda, long int *seed);
//This function generates a random number from a Poisson distribution
//泊松分布
#endif