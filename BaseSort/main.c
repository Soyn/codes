#include <stdio.h>
#include <stdlib.h>
/*
    BaseSort
    Date:2015.1.25
*/
void insertSort(int *a ,int n);
void selectSort(int *a, int n);
void  BubbleSort(int *a ,int n);
void print(int *a,int n);
int main()
{
    int a[6] = {5,2,4,6,1,3};
    //insertSort(a,6);
    //selectSort(a,6);
    BubbleSort(a,6);
    print(a,6);
    return 0;
}
void insertSort(int *a ,int n)
{
    int i,j,t;
    for(i = 1; i < n; i++){
        t = a[i]; // the val will be inserted
        for(j = i-1; j >=0 && a[j] > t; j--){ //if a[j] > k, the loop will run,else run out to insert
                a[j+1] = a[j];
        }
        a[j+1] = t; //exchange the val,the current sort done
    }

}
void selectSort(int *a, int n)
{
    int i ,j,index,minIndex,temp;
    for(i = 0; i < n - 1; i++){
        minIndex = i;
        for(j = i + 1; j < n; j++){
                if(a[minIndex] > a[j]) minIndex = j;
            }
        if(minIndex - i){//move the current minVal to the i
                 temp = a[i];
                 a[i] = a[minIndex];
                 a[minIndex] = temp;
               }
        }
    }
void BubbleSort(int *a, int n)
{
    int i,j,temp;
    for(i = 0;i < n; i++){
    for(j = i+1; j < n; j++){
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    }
    }
}
void print(int *a,int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%-3d",a[i]);
    }
}
