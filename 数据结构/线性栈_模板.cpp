#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct Stack {
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack& S) {
    //��ʼ��ջ
    S.top = -1; //��ʼ��ջ��ָ��
}

int StackEmpty(SqStack S) {
    //�ж�ջ�Ƿ�Ϊ��
    if (S.top == -1) //ջ��
        return 1;
    else //����
        return 0;
}

int Push(SqStack& S, ElemType x) {
    //��ջ����
    if (S.top == MaxSize - 1) //ջ��������
        return 0;
    S.data[++S.top] = x; //ָ���ȼ�1������ջ
    return 1;
}

int Pop(SqStack& S, ElemType& x) {
    //��ջ����
    if (S.top == -1) //ջ�գ�����
        return 0;
    x = S.data[S.top--]; //�ȳ�ջ��ָ���ټ�1
    return 1;
}

int GetTop(SqStack S, ElemType& x) {
    //��ȡջ��Ԫ��
    if (S.top == -1) //ջ�գ�����
        return 0;
    x = S.data[S.top]; //x��¼ջ��Ԫ��
    return 1;
}

void PrintStack(SqStack S) {
    while (S.top > -1) {
        printf("%d", S.data[S.top]);
        S.top--;
    }
}

int main() {
    SqStack L;
    SqStack* S=&L;
    InitStack(*S);
    int x;
    scanf("%d", &x);
    while (x != 0) {
        Push(*S, x);
        scanf("%d", &x);
    }
    PrintStack(*S);
    return 0;
}
