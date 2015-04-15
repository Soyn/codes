#include <stdio.h>
#include <stdlib.h>
/*
    阶乘
    Date：2015.4.2
*/
int factorial1(int n) //递归实现
{
    if(n == 1) return 1;
    else
        return n * factorial1(n-1);
}
int factorial2(int n) //迭代实现
{
    int i,product;
    for(i = product = 1; i <= n; ++i)
    {
        product *= i;
    }
    return product;
}
int main()
{
    printf("%d",factorial2(6));
    return 0;
}
