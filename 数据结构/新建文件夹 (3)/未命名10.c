#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef int ElemType;
//����ջ 
typedef struct {
	ElemType data[100];
	int top;
	int bottom;
}stack;

//����ջ
stack *StackCreate(){
	stack *p=(stack*)malloc(sizeof(stack));//�����¿ռ� 
	if(p==NULL)//����ʧ�� 
	return 0;
	p->bottom=p->top=0;//����ɹ� 
	return p;
}

//��ջ
void StackInput(stack *p,ElemType str){
	p->data[p->top]=str;//����ջ�� 
	p->top++;//ջ��ָ���1 
} 

//��ջ 
ElemType StackOutput(stack *p,ElemType str){
	if(p->top!=p->bottom){//ջ�ǿ� 
		str=p->data[p->top-1];//ջ��������� 
		p->top--;//ջ����1 
		return str;
	}
} 

ElemType StackGetTop(stack *p){
	return (p->data[p->top-1]);
}

int StackEmpty(stack *p){//�ж�ջS�Ƿ�Ϊ��
	if (p->top==p->bottom) return 1;
	else  return 0;
} 

int Check(stack *p){
	char ch;
	char c;
	while((ch=getchar())!='#'){
		switch (ch){
		//����������ջ
		case '(': case '[': case '{': StackInput(p,ch);break; 
		//������������ʱ���ֱ���ƥ�����
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
//��� 
void StackPrint(stack *p){
	while(p->top!=p->bottom){
		printf("%d",p->data[p->top-1]);
		p->top--;
	}
}

//������ 
int main(){
	int i,n,m,a;
	stack *p;//����ջ�� 
	p=StackCreate();//����ջ 
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

