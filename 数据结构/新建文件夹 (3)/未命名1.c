#include<stdio.h>
#define MAXSIZE 1024
typedef int ElemType; 
typedef struct{
	ElemType data[MAXSIZE];
	int top;
}SeqStack;
SeqStack S;
int StackLnit(SeqStack *S){//��ʼ�� 
	S->top=-1;
	return 1;
}
int StackEmpty(SeqStack *S){//�ж�ջS�Ƿ�Ϊ��
	if (S->top==-1) return 1;
	else  return 0;
 } 
int push(SeqStack *S,ElemType x){//��ջ 
 	if(S->top==MAXSIZE-1){
 		printf("ջ��\n");
 		return 0;
	 }
	 S->top++;
	 S->data[S->top]=x;
	 return 1;
 }
 //��ջ(������ջ��Ԫ��):��ջS���գ�ɾ��S��ջ ��Ԫ�أ���������ֵ
int pop(SeqStack *S){
	if(S->top==-1){
		printf("ջ��\n");
		return 0;
	}//ջ�ѿգ��˳�����
	S->top--;
	return 1;
}
ElemType StackGetTop(SeqStack *S){
	return (S->data[S->top]);
}

int Check()
	StackLnit(s);
	char ch;
	char c;
	while((ch=getchar())!='#'){
		switch (ch){
		//����������ջ
		case'(': case'[': case'{': push(s,ch);break; 
		//������������ʱ���ֱ���ƥ�����
		case')':if (StackEmpty(s)) return 0;
				else { c=StackGetTop(s); pop(s); if (c!='(') return 0; } break;
		case ']': if (StackEmpty(s)) retrun 0;
				else { c=StackGetTop(s); pop(s); if (c!='[') return 0; } break;
		case '}':if (StackEmpty(s)) retrun 0; 
				else { c=StackGetTop(s); pop(s); if (c!='{') return 0; } break;
		}
	}
	if (StackEmpty(s)) return 1; else return 0; 
}

