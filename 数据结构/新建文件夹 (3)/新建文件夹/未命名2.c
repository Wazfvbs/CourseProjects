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
void Del2(struct Node* headNode){
	struct Node* rMove=headNode;
	struct Node* pMove=rMove->next;
	while(pMove){
		if(pMove->data%2==0){
			rMove->next=pMove->next;
			pMove=pMove->next;
		}else{
			rMove=rMove->next;
			pMove=pMove->next;
		}
	}
}//删除偶数 
int main(){
	struct Node* list = createList();
	int i;
	scanf("%d",&i);
	while(i!=0){
		insertNodeBylast(list,i);
		scanf("%d",&i);
	}
	Del2(list);
	printList(list);
	return 0;
}
