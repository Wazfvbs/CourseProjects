#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
    int xishu;
    int zhishu;
    struct Node* next;
}Node,*LinkList;

int InitList(LinkList &L){
    L=new Node;
    L->next=NULL;
    return 1;
}
Node* CreateNode(ElemType xishu,ElemType zhishu){
    Node* newNode= new Node;
    newNode->xishu=xishu;
    newNode->zhishu=zhishu;
    newNode->next=NULL;
    return newNode;
}

LinkList CreateList(){
    Node* L=new Node;
    L->next=NULL;
    Node* p=L;
    int len,i;
    int x,z;
    scanf("%d",&len);
    for(i=0;i<len;i++){
        scanf("%d,%d",&x,&z);
        Node* newNode=CreateNode(x,z);
        p->next=newNode;
        p=p->next;
    }
    return L;
}

LinkList Point(LinkList L1,LinkList L2){
    Node* p1=L1->next;
    Node* p2=L2->next;
    Node* L;
    int x,z;
    InitList(L);
    Node* r=L;
    while(p1&&p2){
        if(p1->zhishu>p2->zhishu){
            r->next=p2;
            p2=p2->next;
        }else if(p1->zhishu==p2->zhishu){
            Node* newNode=CreateNode(p1->xishu+p2->xishu,p1->zhishu);
            r->next=newNode;
            p1=p1->next;
            p2=p2->next;
        }else{
            r->next=p1;
            p1=p1->next;
        }
        r=r->next;
    }
    if(p1){
        r->next=p1;
    }else if(p2){
        r->next=p2;
    }
    return L;
}

void PrintList(LinkList L){
    Node* p=L;
    while(p->next!=NULL){
        p=p->next;
        if(p->xishu!=0){
         printf("%d*x^%d ",p->xishu,p->zhishu);
        }

    }
    printf("\n");
}

int main(){
    Node* L1;
    Node* L2;
    InitList(L1);
    InitList(L2);
    L1=CreateList();
    L2=CreateList();
    PrintList(L1);
    PrintList(L2);
    Node* L;
    InitList(L);
    L=Point(L1,L2);
    PrintList(L);
    return 0;


}
