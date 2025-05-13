#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<malloc.h>
#include<string.h>
//����ջ 
typedef struct {
	char data[100];
	int top;
	int bottom;
}stack;
//����ջ
stack* StackCreate() {
	stack* p = (stack*)malloc(sizeof(stack));//�����¿ռ� 
	if (p == NULL)//����ʧ�� 
		return 0;
	p->bottom = p->top = 0;//����ɹ� 
	return p;
}
//��ջ
void StackInput(stack* p, char str) {
	p->data[p->top] = str;//����ջ�� 
	p->top++;//ջ��ָ���1 
}
//��ջ 
char StackOutput(stack* p ) {
	char str;
	if (p->top != p->bottom) {//ջ�ǿ� 
		str = p->data[p->top - 1];//ջ��������� 
		p->top--;//ջ����1 
		return str;
	}
}
char StackGetTop(stack* p) {
	return (p->data[p->top - 1]);
}
int StackEmpty(stack* p) {//�ж�ջS�Ƿ�Ϊ��
	if (p->top == p->bottom) return 1;
	else  return 0;
}
int Check(stack* p) {
	char ch;
	char c;
	while ((ch = getchar()) != '#') {

		switch (ch) {

			//����������ջ

		case '(': case '[': case '{': StackInput(p, ch); break;

			//������������ʱ���ֱ���ƥ�����

		case ')':if (StackEmpty(p)) return 0;

				else { c = StackOutput(p); if (c != '(') return 0; } break;

		case ']': if (StackEmpty(p)) return 0;

				else { c = StackOutput(p); if (c != '[') return 0; } break;
		case '}':if (StackEmpty(p)) return 0;
				else { c = StackOutput(p); if (c != '{') return 0; } break;
		}
	}
	if (StackEmpty(p)) return 1; else return 0;
}
//��� 
void StackPrint(stack* p) {
	while (p->top != p->bottom) {
		printf("%c", p->data[p->top - 1]);
		p->top--;
	}
}
//������ 
int main() {
	stack* p;//����ջ�� 
	p = StackCreate();//����ջ  
	printf("%d", Check(p));
	//StackPrint(p);
	return 0;
}