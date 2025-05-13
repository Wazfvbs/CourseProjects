#include<stdio.h>
#define MAXSIZE 1024
typedef int ElemType; 
typedef struct{
	ElemType data[MAXSIZE];
	int top;
}SeqStack;
SeqStack S;
int StackLnit(SeqStack *S){//初始化 
	S->top=-1;
	return 1;
}
int StackEmpty(SeqStack *S){//判断栈S是否为空
	if (S->top==-1) return 1;
	else  return 0;
 } 
int push(SeqStack *S,ElemType x){//入栈 
 	if(S->top==MAXSIZE-1){
 		printf("栈满\n");
 		return 0;
	 }
	 S->top++;
	 S->data[S->top]=x;
	 return 1;
 }
 //出栈(并返回栈顶元素):若栈S不空，删除S的栈 顶元素，并带回其值
int pop(SeqStack *S){
	if(S->top==-1){
		printf("栈空\n");
		return 0;
	}//栈已空，退出运行
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
		//遇左括号入栈
		case'(': case'[': case'{': push(s,ch);break; 
		//在遇到右括号时，分别检测匹配情况
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

