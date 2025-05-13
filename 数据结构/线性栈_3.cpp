#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
#define MAXSIZE 100
typedef int ElemType;
typedef struct SqStack {
    ElemType data[MAXSIZE];
    int top;
}Stack;
void InitStack(Stack *S) {
    S->top = -1;
}

int longStack(Stack *S)
{
	if (S->top >= 0) return S->top + 1;
	else return 0;
}

int isFull(Stack *S)
{
	if (S->top + 1 == MAXSIZE) return 0;
	else return 1;
}
void push(Stack *S,ElemType c)
{
	if (S->top + 2 <= MAXSIZE)
	{
		S->top++;
		S->data[S->top] = c;
	}
	else
	{
		printf("添加失败！\n");
	}
}
int pop(Stack *S,ElemType &e)
{
	//如果线性栈为空返回0，否则返回栈顶的数据并将栈顶删除
	if (S->top >= 0)
	{
		e = S->data[S->top];
		S->top--;
		return 1;
	}
	else
	{
		return 0;
	}
}
int getTop(Stack *S)
{
	int e;
	e = S->data[S->top];
	return e;
}



int main()
{
	Stack L;
	Stack* S = &L;
	InitStack(S);
	int n,m,x;
	scanf("%d%d", &n,&m);
	printf("%d(10)=", n);
	while (n > 0) {
		x = n % m;
		push(S, x);
		n /= m;
	}
	while (longStack(S)) {
		pop(S, x);
		printf("%d", x);
	}
	printf("(%d)", m);
	return 0;
}

