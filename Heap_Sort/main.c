#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left ,*right;
    int data;
}Node;
int front = 0 ,rear = 0; //
Node *BuildCompleteBTree(int *a, int heap_size, Node **pQueue);
void Max_heapify(Node **pQueue);
void getSequence(Node **pQueue);
int main(void)
{
    int a[8] ={3,1,2,5,7,4,9,8};
    Node *pQueue[9],*h,*p;
    h = BuildCompleteBTree(a,8,pQueue);
    Max_heapify(pQueue);
    getSequence(pQueue);
    int i = 1;
    while(i < 9){
        printf("%-3d",pQueue[i] -> data);
        ++i;
    }
    return 0;
}
Node *BuildCompleteBTree(int *a, int heap_size, Node **pQueue)
{
    int i;
    Node *newNode,*root,*p = NULL;
    for(i = 0; i < heap_size; ++i){

        newNode = (Node*)malloc(sizeof(Node));
        newNode -> data = a[i];
        newNode -> left = newNode -> right = NULL;

        if(i == 0) pQueue[++rear] = root = newNode; //根节点入队
        else{ //不是建根节点时

                if(!p) p = pQueue[++front];
                if(!p -> left){
                        p -> left = newNode; //挂左儿子
                        pQueue[++rear] = newNode; //左儿子入队
                }
                else{

                        p -> right = newNode;
                        pQueue[++rear] = newNode;
                        p =NULL;
                }
        }
    }

    return root;

}
void Max_heapify(Node **pQueue)
{
    int temp;
    Node *largest;
    while(1){
        int k = front,flag = 0;

        while(k > 0){ //向前跑双亲

            largest = pQueue[k];
            if(largest -> data < largest -> left -> data) largest = largest -> left; //判断左儿子

            if(largest->right && largest->data < largest -> right -> data) largest = largest->right; //判断右儿子

            if(largest != pQueue[k]) { //调整保持最大堆
                temp = pQueue[k] -> data;
                pQueue[k] -> data = largest -> data;
                largest -> data = temp;
                flag = 1;
            }
            --k;
        }
        if(!flag) break;
    }
}
void getSequence(Node **pQueue)
{
    Node *root = pQueue[1];
    int temp;
    while(root ->left || root ->right){

        temp = root ->data;
        root -> data = pQueue[rear] -> data;
        pQueue[rear--] -> data = temp;

        if(!pQueue[front] -> right) { //右节点为空时，最后一个双亲只有一个左儿子

                pQueue[front] -> left = NULL;
                --front;
        }
        else
          pQueue[front] -> right = NULL;

          Max_heapify(pQueue);

        }
}
