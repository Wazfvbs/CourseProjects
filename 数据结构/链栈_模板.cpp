#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;
}Stack,*LinkStack;

int InitStack(LinkStack &S){
    S=NULL;
    return 1;
}

Stack* CreateNode(ElemType e){
    Stack* newNode= new Stack;
    newNode->data=e;
    newNode->next=NULL;
    return newNode;
}

int Push (LinkStack &S,ElemType e){
    Stack* newNode=CreateNode(e);
    newNode->next=S;
    S=newNode;
    return 1;
}

int Pop(LinkStack &S,ElemType &e){
    if(S==NULL) return 0;
    else{
        Stack* p=S;
    e=S->data;
    S=S->next;
    free(p);
    return 1;
    }

}

int main (){
    LinkStack S;
    InitStack(S);
    int n,m,r;
    scanf("%d",&n);
    while(n!=0){
        Push(S,n);
        scanf("%d",&n);
    }
    r=Pop(S,m);
    while(r){
        printf("%d ",m);
        r=Pop(S,m);
    }
    return 0;

}







