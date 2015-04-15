#include <stdio.h>
#include <stdlib.h>
/*
    �������
*/
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *DeleteLink(Node *h, int Del_val); //ɾ������Ľڵ�
Node *CreatLink(int *a,int n)
{
    Node *h,*t,*p;
    h = t = NULL;
    int i;
    for(i = 0; i < n; i++){
        p = (Node*)malloc(sizeof(Node)); //���䵥Ԫ
        p -> data = a[i]; //������ֵ
        p -> next = NULL;
        if(h){
            t = t -> next = p; //����ͷ�ڵ�
        }
        else{
            h = t = p; //��ͷ�ڵ�
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
     if(q){  //ɾ����ͷ�ڵ�
        q -> next = p -> next;
     }
     else{ //ɾ��ͷ�ڵ�
        h = p -> next;
     }
     free(p);
     return h;
}
