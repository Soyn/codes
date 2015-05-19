#include <stdio.h>
#include <stdlib.h>
int MaxSubseqSum(int *a, int n);
void MaxSubseqSum1();
int main()
{
    MaxSubseqSum1();
    return 0;
}
void MaxSubseqSum1()
{


    int i,j,n,ThisSum,MaxSum;
    ThisSum = MaxSum = 0;
    scanf("%d", &n);

    int a[n];
    for(i = 0; i < n; ++i)
        scanf("%d",&a[i]);

    for(i = 0; i < n; ++i)
    {
        ThisSum += a[i]; //�����ۼ�
        if(ThisSum > MaxSum) MaxSum = ThisSum; //���ָ���ĺ͸�������
        else{ //�����ǰ��Ϊ����������ʹ����Ĳ��ֺ����󣬸�0����
            if(ThisSum < 0) ThisSum = 0;
        }
    }
       printf("%d", MaxSum);
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
