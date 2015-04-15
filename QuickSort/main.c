#include <stdio.h>
#include <stdlib.h>
/*
    快速排序
    Date：2015.1.21
*/

void QuickSort1(int *a,int n);
void QuickSort2(int *a, int p, int r);
int Partition(int *a,int p,int r);
int HoarePartition(int *a , int p ,int r);
int main()
{
    int a[5] ={10,2,11,3,5},i;
    //QuickSort1(a,5);
    QuickSort2(a,0,4);
    for(i = 0; i < 5; i++){
        printf("%-3d",a[i]);
    }
    return 0;
}
void QuickSort1(int *a ,int n)
{
    int left = 0, right = n-1,key = a[0];
    while(left < right){ //递归结束条件
        for(;left < right; right--){ //从后向前找比key小的值
            if(a[right] < key){
                a[left++] = a[right];
                break;
            }
        }
        for(;left < right; left++){ //从前向后找比key大的值
            if(a[left] > key){
                a[right--] = a[left];
                break;
            }
        }
        a[left] = key;
        QuickSort1(a,left);
        QuickSort1(a+left+1,n-left-1);
    }
}
void QuickSort2(int *a,int p, int r)
{
    int q; //标准值的下标
    if(p < r){  //递归结束条件
        q = HoarePartition(a,p,r); //划分区域
        QuickSort2(a,p,q-1);
        QuickSort2(a,q+1,r);
    }
}
int Partition(int *a, int p, int r)
{
    int key = a[r],temp;
    int i = p-1,j;
    for(j = p;j < r;j++){
        if(a[j] <= key){ //将比key小的值往前放
            temp = a[++i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i+1];//将标准值放在i+1的位置
    a[i+1] = a[r];
    a[r] = temp;
    return i+1;
}
int HoarePartition(int *a, int p ,int r)
{
    printf("HoarePartition has been invoked!\n");
    int x = a[p];
    int temp,i,j;
    i = p;
    j = r;
    while( 1 ){
        while( a[j] > x )
            j--;
        while( a[i] < x )
            i++;
        if( i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else return j;
    }
}
