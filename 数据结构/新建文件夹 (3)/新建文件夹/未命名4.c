#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};//�ṹ�� 
struct Node* createList(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}//�����б�
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next= NULL;
	return newNode;
}//������� 
void printList(struct Node* headNode){
	struct Node* pMove=headNode->next;
	while(pMove){
		printf("%d ",pMove->data);
		pMove=pMove->next;
	}
	printf("\n");
}//��ӡ���� 
void insertNodeByHead(struct Node* headNode,int data){
	struct Node* newNode=createNode(data);
	newNode->next =headNode->next;
	headNode->next=newNode;
}//ͷ�巨 
void insertNodeBylast(struct Node* headNode,int data){
	struct Node* pMove=headNode;
	struct Node* newNode=createNode(data);
	while(pMove->next) pMove=pMove->next;
	pMove->next=newNode;
	newNode->next=NULL;
}//β�巨 
void Fenkai(struct Node* headNode1,struct Node* headNode2){
	struct Node* rMove=headNode1;
	struct Node* pMove=headNode1->next;
	struct Node* qMove=headNode2;
	while(pMove){
		if(pMove->data%2==0){
			rMove->next=pMove->next;
			qMove->next=pMove;
			pMove=pMove->next;
			qMove=qMove->next;
			qMove->next=NULL;
		}else{
			rMove=rMove->next;
			pMove=pMove->next;
		} 
	}
}
int main(){
	struct Node* list1= createList();
	struct Node* list2= createList();
	int i;
	scanf("%d",&i);
	while(i!=0){
		insertNodeBylast(list1,i);
		scanf("%d",&i);
	}
	Fenkai(list1,list2);
	printList(list1);
	printList(list2);
	return 0;
}
