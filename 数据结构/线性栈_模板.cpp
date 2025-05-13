#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct Stack {
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack& S) {
    //初始化栈
    S.top = -1; //初始化栈顶指针
}

int StackEmpty(SqStack S) {
    //判断栈是否为空
    if (S.top == -1) //栈空
        return 1;
    else //不空
        return 0;
}

int Push(SqStack& S, ElemType x) {
    //进栈操作
    if (S.top == MaxSize - 1) //栈满，报错
        return 0;
    S.data[++S.top] = x; //指针先加1，再入栈
    return 1;
}

int Pop(SqStack& S, ElemType& x) {
    //出栈操作
    if (S.top == -1) //栈空，报错
        return 0;
    x = S.data[S.top--]; //先出栈，指针再减1
    return 1;
}

int GetTop(SqStack S, ElemType& x) {
    //获取栈顶元素
    if (S.top == -1) //栈空，报错
        return 0;
    x = S.data[S.top]; //x记录栈顶元素
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
