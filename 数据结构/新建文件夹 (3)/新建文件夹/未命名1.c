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
void Paixu(struct Node* headNode){
	struct Node* lMove=headNode;
	struct Node* rMove=lMove->next;
	struct Node* pMove=rMove->next;
	int temp,r;
	while(pMove){
		if(rMove->data>pMove->data){
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
		if(rMove->data>pMove->data){
			r=1;
			break;
		}
		rMove=rMove->next;
		pMove=pMove->next;
	}
	if(r) Paixu(headNode);

}//���� 
int main(){
	struct Node* list = createList();
	int ins,i;
	scanf("%d",&ins);
	scanf("%d",&i);
	while(i!=0){
		insertNodeBylast(list,i);
		scanf("%d",&i);
	}
	insertNodeBylast(list,ins);
	Paixu(list);
	printList(list);
	return 0;
}
