#include <stdio.h>
#include <stdlib.h>
/*
    ¶þ·Ö²éÕÒ
    Date:2015.2.3
*/
void BinarySearch(int *a,int low, int high,int val);
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,21};
    BinarySearch(a,0,9,1);
    return 0;
}
void BinarySearch(int *a, int low, int high,int val)
{
    int mid = ( low + high ) / 2;
    if(low <= high){
        if(a[mid] == val){
            printf("the value's index in arrary is %d",mid);
        }
        else{
            if(a[mid] < val) {
                BinarySearch(a,mid+1,high,val);
            }
            else{
                BinarySearch(a,low,mid-1,val);
            }
        }
    }
    else{
        printf("the arrary doesn't exits such value");
    }
}
