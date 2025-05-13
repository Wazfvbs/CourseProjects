#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef  int ElemType;
typedef struct Queue{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;
}
int IsEmpty(SqQueue Q){
    if(Q.front==Q.rear) return 1;
    else return 0;
}
int EnQueue(SqQueue &Q,ElemType e){
    if((Q.rear+1)%MaxSize==Q.front) return 0;
    else{
        Q.data[Q.rear]=e;
        Q.rear=(Q.rear+1)%MaxSize;
        return 1;
    }
}
int DeQueue(SqQueue &Q,ElemType &e){
    if (Q.rear == Q.front) return 0;
    else{
        e = Q.data[Q.front];
        Q.front = (Q.front + 1)%MaxSize;
        return 1;
    }
}
int main(){
    SqQueue q;
    SqQueue *Q=&q;
    InitQueue(*Q);
    int x,r;
    scanf("%d",&x);
    while(x!=0){
        EnQueue(*Q,x);
        scanf("%d" ,&x);
    }
    r=DeQueue(*Q,x);
    while(r){
        printf("%d ",x);
        r=DeQueue(*Q,x);
    }
    return 0;

}
