#include <stdio.h>
#include <stdlib.h>
/*
    �׳�
    Date��2015.4.2
*/
int factorial1(int n) //�ݹ�ʵ��
{
    if(n == 1) return 1;
    else
        return n * factorial1(n-1);
}
int factorial2(int n) //����ʵ��
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
