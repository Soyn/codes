#include <stdio.h>
#include <stdlib.h>
/*
    链表操作
*/
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *DeleteLink(Node *h, int Del_val); //删除链表的节点
Node *CreatLink(int *a,int n)
{
    Node *h,*t,*p;
    h = t = NULL;
    int i;
    for(i = 0; i < n; i++){
        p = (Node*)malloc(sizeof(Node)); //分配单元
        p -> data = a[i]; //数据域赋值
        p -> next = NULL;
        if(h){
            t = t -> next = p; //建非头节点
        }
        else{
            h = t = p; //建头节点
        }
    }
    return h;
}

int main()
{
    Node *h,*p;
    int a[5] = {1,2,3,4,5};
    h = CreatLink(a,5);
    h = DeleteLink(h,1);
    for(p = h; p != NULL; p = p->next)
        printf("%-3d",p -> data);
    return 0;
}
Node *DeleteLink(Node *h, int Del_val)
{
    Node *p,*q = NULL;
    for(p = h; p != NULL && p ->data != Del_val; p = p->next){
        q = p;
    }
     if(q){  //删除非头节点
        q -> next = p -> next;
     }
     else{ //删除头节点
        h = p -> next;
     }
     free(p);
     return h;
}
