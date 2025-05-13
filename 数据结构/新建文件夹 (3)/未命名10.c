#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef int ElemType;
//定义栈 
typedef struct {
	ElemType data[100];
	int top;
	int bottom;
}stack;

//创建栈
stack *StackCreate(){
	stack *p=(stack*)malloc(sizeof(stack));//分配新空间 
	if(p==NULL)//分配失败 
	return 0;
	p->bottom=p->top=0;//分配成功 
	return p;
}

//入栈
void StackInput(stack *p,ElemType str){
	p->data[p->top]=str;//存入栈中 
	p->top++;//栈顶指针加1 
} 

//出栈 
ElemType StackOutput(stack *p,ElemType str){
	if(p->top!=p->bottom){//栈非空 
		str=p->data[p->top-1];//栈顶内容输出 
		p->top--;//栈顶减1 
		return str;
	}
} 

ElemType StackGetTop(stack *p){
	return (p->data[p->top-1]);
}

int StackEmpty(stack *p){//判断栈S是否为空
	if (p->top==p->bottom) return 1;
	else  return 0;
} 

int Check(stack *p){
	char ch;
	char c;
	while((ch=getchar())!='#'){
		switch (ch){
		//遇左括号入栈
		case '(': case '[': case '{': StackInput(p,ch);break; 
		//在遇到右括号时，分别检测匹配情况
		case ')':if (StackEmpty(p)) return 0;
				else {StackOutput(p,c); if (c!='(') return 0; } break;
		case ']': if (StackEmpty(p)) return 0;
				else {StackOutput(p,c); if (c!='[') return 0; } break;
		case '}':if (StackEmpty(p)) return 0; 
				else {StackOutput(p,c); if (c!='{') return 0; } break;
		}
	}
	if (StackEmpty(p)) return 1; else return 0; 
}
//输出 
void StackPrint(stack *p){
	while(p->top!=p->bottom){
		printf("%d",p->data[p->top-1]);
		p->top--;
	}
}

//主函数 
int main(){
	int i,n,m,a;
	stack *p;//定义栈名 
	p=StackCreate();//创建栈 
	scanf("%d%d",&m,&n);
	a=m;
	while(m>0){
		i=m%n;
		StackInput(p,i);
		m/=n;
	}
	printf("%d(10)=",a);
	StackPrint(p);
	printf("(%d)",n);
	return 0;
}

