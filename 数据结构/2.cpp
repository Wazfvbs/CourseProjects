#include<stdio.h>

#include<stdlib.h>

typedef int ElemType;

typedef struct QNode{

    ElemType data;

    struct QNode *next;

}QNode,*QueuePtr;

typedef struct{

    QueuePtr front;

    QueuePtr rear;

}LinkQueue;



//CHUSHIHUA

int InitQueue(LinkQueue &Q){

    Q.front=Q.rear=new QNode;

    Q.front->next=NULL;

    return 1;

}



QNode* createNode(ElemType e){

    QNode* p=new QNode;

    p->data=e;

    p->next=NULL;

    return p;

}



int EnQueue(LinkQueue &Q,ElemType e){

    QNode* p=createNode(e);

    Q.rear->next=p;

    Q.rear=p;

    return 1;

}

int DeQueue(LinkQueue &Q,ElemType &e){

    QNode* p=Q.front->next;

    e=p->data;

    Q.front->next=p->next;

    if(Q.rear==p) Q.rear=Q.front;

    delete p;

    return 1;

}



int main(){

    LinkQueue Q;

    int n,i,e,j;

    scanf("%d",&n);

    InitQueue(Q);

    EnQueue(Q,1);

    for(i=2;i<=n;i++){

        EnQueue(Q,1);

        for (j=1;j<i-1;j++){

            printf("%d  ",Q.front->next->data);

            DeQueue(Q,e);

            e+=Q.front->next->data;

            EnQueue(Q,e);

        }

        printf("%d  \n",Q.front->next->data);

        DeQueue(Q,e);

        EnQueue(Q,1);

    }

    while(Q.front!=Q.rear){

        printf("%d  ",Q.front->next->data);

        DeQueue(Q,e);

    }

    return 0;

}

