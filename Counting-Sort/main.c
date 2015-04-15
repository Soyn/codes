#include <stdio.h>
#include <stdlib.h>
/*    计数排序
    Date:2015.2.6
*/
const int N = 8;
int getMax(int *a);
void CountingSort(int *a, int *b, int k);
int main()
{
    int k, i, a[N] ,b[N];
    a[N] = {2,5,3,0,2,3,0,3};
    b[N] = {-1};
    k = getMax(a);
    CountingSort(a,b,k);
    for(i = 0; i < N; i++)
        printf("%-3d",b[i]);
    return 0;
}
int getMax(int *a)
{
    int i,max = a[0];
    for(i = 1; i < N; i++)
    {
        max = a[i] > max ? max = a[i] : max;
    }
    return max;
}
void CountingSort(int *a, int *b, int k)
{
    int i,c[k];
    for(i = 0; i < k; i++){//初始化临时储存数组
        c[i] = 0;
    }
    for(i = 0; i < N; i++){ //get the numbers of per elements in a[N]
        ++c[a[i]];
    }
    for(i = 1; i < k; i++){ //get the elements which less or equel to a[i]
        c[i] = c[i] + c[i-1];
    }
    for(i = N - 1; i >= 0; i--){
        b[c[a[i]]] = a[i];
        --c[i];
    }
}
