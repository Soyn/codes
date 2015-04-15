#include <stdio.h>
#include <stdlib.h>
/*
    递归实现八皇后
    Date：2015。1.21
*/
int column[8] = {0};
int Q[8];
int left[15] = {0}; //定义左斜线
int right[15] = {0}; //定义右斜线
void Queen(int row);
int IsTrue(int row,int col); //判断是否可以放皇后
void PlaceQueen(int row, int col);
void ResetQueen(int row, int col); //抹皇后
void print();
int cnt = 0;;
int main()
{
    Queen(0);
    return 0;
}
void Queen(int row)
{
    int col;
    for(col = 0; col < 8; col++){
        if(IsTrue(row,col)){
            PlaceQueen(row,col); //放皇后
            if(row < 7) Queen(row+1);

            else{
                printf("第%d组解\n",++cnt);
                print(); //输出一组解

            }

           ResetQueen(row,col); //抹去皇后

        }
    }
}
int IsTrue(int row ,int col)
{
    int tag = 0;
    if(column[col] == 0&&left[row+col] == 0&&right[row - col +7] == 0) //在位置上可以放皇后时
        ++tag;
    return tag;
}
void PlaceQueen(int row ,int col)
{
     column[col] = 1;
     left[row+col] = 1;
     right[row - col +7] = 1;
     Q[row] = col;

}
void ResetQueen(int row, int col)
{
    column[col] = 0;
    left[row+col] = 0;
    right[row - col +7] = 0;
}
void print()
{
    int i,j;
    for(i = 0;i < 8; i++){
     for(j = 0; j < 8; j++){
        if(Q[i] == j) putchar('Q');
            else
                putchar('+');
    }
    putchar('\n');
}
}
