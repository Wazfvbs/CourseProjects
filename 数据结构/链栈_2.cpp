/*试编写算法，把单向链表（值域为整型）中元素逆置（不允许申请新的结点空间）。

输入：输入方式和题目2 一样，以0作为结束输入的标记，元素不一样有序

输出：逆置后的单链表，元素之间用一个空格分隔*/
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct SNode								//定义一个结构体
{
	ElemType data;
	struct SNode* next;
}StackNode,*LinkStack;
/*//初始化
int InitList(Node* L)							//带有头节点的单链表的初始化
{
	L = (Node*)malloc(sizeof(Node));
	if (L != NULL) L->next = NULL;
	return 1;
}
//创建结点
Node* CreateNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode ) {
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}
//打印链表
void printList(Node* headNode) {
	Node* pMove = headNode->next;
	while (pMove) {
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
//尾插法
void insertNodeBylast(Node* headNode, int data) {
	Node* pMove = headNode;
	Node* newNode = CreateNode(data);
	while (pMove->next) pMove = pMove->next;
	pMove = newNode;
	newNode->next = NULL;
}
//逆置
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

}//逆置


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


//链表初始化
int InitList(LinkList &L) {
	L = new LNode;
	L->data = NULL;
	return 1;
}
//尾插法初始化
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

//插入结点
void InsertNode(LinkList& L, int n) {
	LNode* newNode = new LNode;
	newNode->data = n;
	newNode->next = L->next;
	L->next = newNode;
}



//逆置
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

//打印链表
void PrintLink(LinkList L) {
	LNode* p = L->next;
	while (p != NULL) {
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
}*/
//初始化
int InitStack(LinkStack& S) {
	StackNode* s = NULL;
	return 1;
}
int Push(LinkStack& S, ElemType e) {
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return 1;
}
int Pop(LinkStack& S, ElemType& e) {
	if (S == NULL) return 0;
	else {
		e = S->data;
		StackNode* p = S;
		S = S->next;
		delete p;
		return 1;
	}
}
void PrintStack(LinkStack S) {
	StackNode* p = S;
		while (p != NULL) {
			printf("%d ", p->data);
			p = p->next;
		}

}
int main() {
	StackNode* S;
	InitStack(S);
	int n,m;
	scanf("%d", &n);
	while (n != 0) {
		Push(S, n);
		scanf("%d", &n);
	}
	PrintStack(S);
	return 0;
}
