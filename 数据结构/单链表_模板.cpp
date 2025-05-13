#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;
}Node,*LinkList;

Node* CreateNode(ElemType data){
    Node* newNode=new(Node);
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

LinkList CreateList(){
    int x;
    LinkList L=new Node;
    L->next=NULL;
    Node *p=L;
    scanf("%d",&x);
    while(x!=0){
        Node* newNode=CreateNode(x);
        p->next=newNode;
        scanf("%d",&x);
        p=p->next;
    }
    return L;
}

void PrintList(LinkList L){
    Node *p=L;
    while(p->next!=NULL){
        p=p->next;
        printf("%d ",p->data);
    }
}

Node* Hebing(LinkList &L1,LinkList &L2){
    Node* p=L1->next;
    while(p->next){
        p=p->next;
    }
    p->next=L2->next;
    return L1;
}

void Paixu(LinkList &L){
    Node* p=L->next;
    Node* q=L->next;
    Node* tail=L->next;
    int count=0,i,num;
    while(p){
		count++;
		p = p->next;
	}
    for(i = 0; i < count - 1; i++)
	{
		num = count - i - 1;
		q = L->next;
		p = q->next;
		tail = L;
		while(num--){
			if(q->data > p->data){
				q->next = p->next;
				p->next = q;
				tail->next = p;
			}
			tail = tail->next;
			q = tail->next;
			p = q->next;
        }
	}

}

int main(){
    LinkList L1;
    LinkList L2;
    L1=CreateList();
    L2=CreateList();
    Hebing(L1,L2);
    Paixu(L1);
    PrintList(L1);
    return 0;

}
