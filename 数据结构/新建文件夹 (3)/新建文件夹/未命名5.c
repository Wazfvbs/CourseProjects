#include<stdio.h>
#include<stdlib.h>
struct Node{
	int xishu;
	int zhishu;
	struct Node* next;
};//结构体 
struct Node* createList(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}//创建列表
struct Node* createNode(int xishu,int zhishu){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->xishu=xishu;
	newNode->zhishu=zhishu;
	newNode->next= NULL;
	return newNode;
}//创建结点 
void printList(struct Node* headNode){
	struct Node* pMove=headNode->next;
	while(pMove){
		if(pMove->xishu!=0){
			printf("%d*x^%d ",pMove->xishu ,pMove->zhishu);
		}
		pMove=pMove->next;
	}
	printf("\n");
}//打印链表 
void insertNodeBylast(struct Node* headNode,int xishu,int zhishu){
	struct Node* pMove=headNode;
	struct Node* newNode=createNode(xishu,zhishu);
	while(pMove->next) pMove=pMove->next;
	pMove->next=newNode;
	newNode->next=NULL;
}//尾插法 
void Hebing(struct Node* headNode1,struct Node* headNode2,struct Node* headNode3){
	struct Node* pMove1=headNode1->next;
	struct Node* pMove2=headNode2->next;
	struct Node* pMove3=headNode3;
	struct Node* newNode;
	int x;
	while(pMove1&&pMove2){
		if(pMove1->zhishu>pMove2->zhishu){
			newNode=createNode(pMove2->xishu,pMove2->zhishu);
			pMove3->next=newNode;
			pMove3=pMove3->next;
			pMove2=pMove2->next;
		}else if(pMove1->zhishu<pMove2->zhishu){
			newNode=createNode(pMove1->xishu,pMove1->zhishu);
			pMove3->next=newNode;
			pMove3=pMove3->next;
			pMove1=pMove1->next;
		}else if(pMove1->zhishu==pMove2->zhishu){
			x=pMove1->xishu+pMove2->xishu;
			newNode=createNode(x,pMove1->zhishu);
			pMove3->next=newNode;
			pMove3=pMove3->next;
			pMove1=pMove1->next;
			pMove2=pMove2->next;
		}
	}
	if(pMove1) pMove3->next=pMove1;
	else if(pMove2) pMove3->next=pMove2;
}
int main(){
	struct Node* list1= createList();
	struct Node* list2= createList();
	struct Node* list3= createList();
	int leni,ix,iz,lenj,jx,jz,i;
	scanf("%d",&leni);
	for(i=leni;i>0;i--){
		scanf("%d,%d",&ix,&iz);
		insertNodeBylast(list1,ix,iz);
	}
	scanf("%d",&lenj);
	for(i=lenj;i>0;i--){
		scanf("%d,%d",&jx,&jz);
		insertNodeBylast(list2,jx,jz);
	}
	Hebing(list1,list2,list3);
	printList(list3);
	return 0;
}
