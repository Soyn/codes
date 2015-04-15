#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    Å£¶Ù·¨¿ª·½
    Date£º2015.3.21
*/
double preGuess = 1;
double Sqrt_iter(double guess,double x);
double improve(double guess, double x);
int good_enough(double guess,double x);
int main()
{
    double x = 2;
    printf("%lf",Sqrt_iter(1,2));
    return 0;
}
double Sqrt_iter(double guess,double x)
{

    if(good_enough(guess,x)) return guess;
        else{
            printf("cccc\n");
            return Sqrt_iter(improve(guess,x),x);
        }
}
int good_enough(double guess,double x)
{
    int tag = 0;
    if (fabs(guess * guess - x) < 0.001) tag = tag + 1;
    return tag;
}
double improve(double guess,double x)
{
    return (x / guess + guess) / 2;
}
