#include <stdio.h>
#include <stdlib.h>
int MaxSubseqSum(int *a, int n);
int main()
{
    int a[6] ={2,4,5,-1,8,9};
    printf("MaxSum = %d",MaxSubseqSum2(a,6));
    return 0;
}
int MaxSubseqSum1(int *a,int n)
{

    int i,j,ThisSum,MaxSum;
    ThisSum = MaxSum = 0;
    for(i = 0; i < n; ++i)
    {
        ThisSum += a[i]; //向右累加
        if(ThisSum > MaxSum) MaxSum = ThisSum; //发现更大的和更新最大和
        else{ //如果当前和为负数，则不能使后面的部分和增大，赋0抛弃
            if(ThisSum < 0) ThisSum = 0;
        }
    }
      return MaxSum;
}
int MaxSubseqSum2(int *a, int n)
{
    int i,j,ThisSum,MaxSum = 0;
    for(i = 0; i < n; ++i){
        ThisSum = 0;
        for(j = i; j < n; ++j){
            ThisSum += a[j];
            if(ThisSum > MaxSum) MaxSum = ThisSum;
        }
    }
    return MaxSum;
}
