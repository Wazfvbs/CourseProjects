#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Queue{
    ElemType data;
    struct Queue* next;
}Node;
typedef struct{
    Node* front;
    Node* rear;
}LinkQueue;

int InitQueue(LinkQueue &Q){
    Q.front=Q.rear=new Node;
    Q.front->next=NULL;
}

int EnQueue(LinkQueue &Q,ElemType e){
    Node* p;
    p=new Node;
    p->data=e;
    Q.rear->next=p;
    Q.rear=p;
    return 1;

}

int DeQueue(LinkQueue &Q,ElemType &e){
    Node* p;
    if(Q.front==Q.rear) return 0;
    else{
        p=Q.front->next;
        e=p->data;
        Q.front->next=p->next;
        if(Q.rear==p) Q.rear=Q.front;
        free(p);
        return 1;
    }
}

int LengthQueue(LinkQueue Q){
    int len=0;
    while(Q.front->next!=NULL){
        Q.front=Q.front->next;
        len++;
    }
    return len;
}

