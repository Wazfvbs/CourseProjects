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
    Node* L;
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

int FindNode(LinkList L,ElemType &e,ElemType &c){
    int max,maxi=1,i=1;
    Node* p=L->next;
    max=p->data;
    while(p){
        if(p->data>max){
            maxi=i;
            max=p->data;
        }
        p=p->next;
        i++;

    }
    e=max;
    c=maxi;
    return 1;
}

int main(){
    Node* L;
    L=CreateList();
    int x,y;
    FindNode(L,x,y);
    printf("%d %d ",x,y);
    return 0;
}
