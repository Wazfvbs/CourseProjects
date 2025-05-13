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
void insertNodeBylast(struct Node* headNode,int data){
	struct Node* pMove=headNode;
	struct Node* newNode=createNode(data);
	while(pMove->next) pMove=pMove->next;
	pMove->next=newNode;
	newNode->next=NULL;
}//尾插法 
void Quchong(struct Node* headNode){
	struct Node* rMove=headNode->next;
	struct Node* pMove=rMove->next;
	while(pMove){
		if(rMove->data==pMove->data){
			rMove->next=pMove->next;
			pMove=pMove->next;
		}else{
			rMove=rMove->next;
			pMove=pMove->next;
		}
	}
}
void Hebing(struct Node* headNode1,struct Node* headNode2){
	struct Node* rMove1=headNode1;
	struct Node* pMove1=headNode1->next;
	struct Node* pMove2=headNode2->next;
	while(pMove1&&pMove2){
		if(pMove1->data>pMove2->data){
			rMove1->next=pMove2;
			pMove2=pMove2->next;
			rMove1=rMove1->next;
			rMove1->next=pMove1;
			
		}else if(pMove1->data<pMove2->data){
			rMove1=rMove1->next;
			pMove1=pMove1->next;
		}else if(pMove1->data==pMove2->data){
			pMove2=pMove2->next;
		}
	}
	if(pMove2) pMove1->next=pMove2;
	Quchong(headNode1);
}
int main(){
	struct Node* list1= createList();
	struct Node* list2= createList();
	int i,j;
	scanf("%d",&i);
	while(i!=0){
		insertNodeBylast(list1,i);
		scanf("%d",&i);
	}
	scanf("%d",&j);
	while(j!=0){
		insertNodeBylast(list2,j);
		scanf("%d",&j);
	}
	Hebing(list1,list2);
	printList(list1);
	return 0;
}
