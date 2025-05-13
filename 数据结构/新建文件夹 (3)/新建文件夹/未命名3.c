#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};//结构体 
struct Node* createList(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}//创建列表
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next= NULL;
	return newNode;
}//创建结点 
void printList(struct Node* headNode){
	struct Node* pMove=headNode->next;
	while(pMove){
		printf("%d ",pMove->data);
		pMove=pMove->next;
	}
	printf("\n");
}//打印链表 
void insertNodeByHead(struct Node* headNode,int data){
	struct Node* newNode=createNode(data);
	newNode->next =headNode->next;
	headNode->next=newNode;
}//头插法 
void insertNodeBylast(struct Node* headNode,int data){
	struct Node* pMove=headNode;
	struct Node* newNode=createNode(data);
	while(pMove->next) pMove=pMove->next;
	pMove->next=newNode;
	newNode->next=NULL;
}//尾插法 
void Paixu(struct Node* headNode){
	struct Node* lMove=headNode;
	struct Node* rMove=lMove->next;
	struct Node* pMove=rMove->next;
	int temp,r;
	while(pMove){
		if(rMove->data<pMove->data){
			temp=pMove->data;
			pMove->data=rMove->data;
			rMove->data=temp;
		}
		lMove=lMove->next;
		rMove=rMove->next;
		pMove=pMove->next;	
	}
	rMove=headNode->next;
	pMove=rMove->next;
	while(pMove){
		if(rMove->data<pMove->data){
			r=1;
			break;
		}
		rMove=rMove->next;
		pMove=pMove->next;
	}
	if(r) Paixu(headNode);

}//排序 
void Hebing(struct Node* headNode1,struct Node* headNode2){
	struct Node* pMove1=headNode1;
	while(pMove1->next)
		pMove1=pMove1->next;
	pMove1->next=headNode2->next;
}//合并 
int main(){
	struct Node* list1= createList();
	struct Node* list2= createList();
	int i;
	scanf("%d",&i);
	while(i!=0){
		insertNodeBylast(list1,i);
		scanf("%d",&i);
	}
	scanf("%d",&i);
	while(i!=0){
		insertNodeBylast(list2,i);
		scanf("%d",&i);
	}
	Hebing(list1,list2);
	Paixu(list1);
	printList(list1);
	return 0;
}
