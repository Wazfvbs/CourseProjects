#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode								//����һ���ṹ��
{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
/*//��ʼ��
int InitList(Node* L)							//����ͷ�ڵ�ĵ�����ĳ�ʼ��
{
	L = (Node*)malloc(sizeof(Node));
	if (L != NULL) L->next = NULL;
	return 1;
}
//�������
Node* CreateNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode ) {
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}
//��ӡ����
void printList(Node* headNode) {
	Node* pMove = headNode->next;
	while (pMove) {
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
//β�巨
void insertNodeBylast(Node* headNode, int data) {
	Node* pMove = headNode;
	Node* newNode = CreateNode(data);
	while (pMove->next) pMove = pMove->next;
	pMove = newNode;
	newNode->next = NULL;
}
//����
void Reverse(Node* headNode) {
	Node* pMove = headNode->next;
	Node* rMove = headNode;
	headNode->next = NULL;
	while (pMove != NULL) {
		rMove = pMove;
		pMove = pMove->next;
		rMove->next = headNode->next;
		headNode->next = rMove;
	}

}//����


int main()
{
	Node L;
	InitList(&L);
	int n;
	scanf("%d", &n);
	while (n != 0) {
		insertNodeBylast(&L, n);
		scanf("%d", &n);
	}
	printList(&L);
	return 0;
}
*/

//�����ʼ��
int InitList(LinkList &L) {
	L = new LNode;
	L->data = NULL;
	return 1;
}
//β�巨��ʼ��
void CreateList(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* r = L;
	while (n != 0) {
		LNode* p = new LNode;
		p->data = n;
		p->next = NULL;
		r->next = p;
		r = p;
		scanf("%d", &n);
	}
}

//����
void ReverseLink(LinkList& L) {
	LNode* p = L->next;
	LNode* r;
	L->next = NULL;
	while (p) {
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
}

//��ӡ����
void PrintLink(LinkList L) {
	LNode* p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	LinkList L;
	int n;
	scanf("%d", &n);
	CreateList(L,n);
	ReverseLink(L);
	PrintLink(L);
	return 0;
}
