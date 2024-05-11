#ifndef _SIGNALS_H_
#define _SIGNALS_H_

// basic signals
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

// advanced signals
void sinwn(double a[], double f[], double ph[], int m, 
double fs, double snr, long seed, double x[], int n);
//This function generates a sinusoidal signal with white noise
//产生含高斯白噪声的正弦组合信号
//a: 各信号振幅，长度m
//f: 各信号频率，长度m
//ph: 各信号相位，长度m
//m: 信号个数
//fs: 采样频率
//snr: 信噪比（dB）
//seed: 随机数种子
//x: 输出信号
//n: 信号长度

#endif