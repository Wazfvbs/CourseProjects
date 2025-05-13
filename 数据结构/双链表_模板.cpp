#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *prior,*next;
}Node,*LinkList;

Node* CreateNode(ElemType e){
    Node* newNode=new Node;
    newNode->data=e;
    newNode->prior=NULL;
    newNode->next=NULL;
    return newNode;
}

LinkList CreateList (){
    LinkList L=new Node;
    L->next=NULL;
    L->prior=NULL;
    Node* p =L;
    int x;
    scanf("%d",&x);
    while(x!=0){
        Node* newNode=CreateNode(x);
        p->next=newNode;
        newNode->prior=p;
        p=p->next;
        scanf("%d",&x);
    }
    return L;
}
void PrintList(LinkList L){
    Node* p=L->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    LinkList L;
    L=CreateList();
    PrintList(L);
    return 0;
}

