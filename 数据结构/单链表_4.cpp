#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;

}Node,*LinkList;

int InitList(LinkList &L){
    L=new Node;
    L->next=NULL;
    return 1;
}

Node* CreateNode(ElemType e){
    Node* newNode=new Node;
    newNode->data=e;
    newNode->next=NULL;
    return newNode;
}

Node* CreateList(){
    Node* L=new Node;
    InitList(L);
    Node* p=L;
    int x;
    scanf("%d",&x);
    while(x!=0){
        Node* newNode=CreateNode(x);
        p->next=newNode;
        p=p->next;
        scanf("%d",&x);
    }
    return L;

}

void PrintList (LinkList L){
    Node* p=L;
    while(p->next){
        p=p->next;
        printf("%d",p->data);
    }
}

void InSertL(LinkList &L,ElemType e){
    Node* p=L;
    Node* newNode=CreateNode(e);
    while(p->next){
        if(e<p->next->data){
            newNode->next=p->next;
            p->next=newNode;
            break;
        }

        p=p->next;
    }

}

int main(){
    Node* L;
    InitList (L);
    L=CreateList();
    int x;
    scanf("%d",&x);
    InSertL(L,x);
    PrintList(L);
    return 0;

}
