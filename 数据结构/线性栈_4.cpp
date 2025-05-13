#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef char ElemType;
typedef struct Stack{
    ElemType data[MAXSIZE];
    int top;
}SqStack;
void InitStack(SqStack &S){
    S.top=-1;
}
int Push(SqStack &S,ElemType e){
    if(S.top+1>=MAXSIZE) return 0;
    S.top++;
    S.data[S.top]=e;
    return 1;
}
int Pop2(SqStack &S,ElemType &e){
    if(S.top-1<0) return 0;
    e=S.data[S.top];
    S.top--;
    return 1;
}


int Pop(SqStack &S, ElemType &x) {
    //出栈操作
    if (S.top == -1) //栈空，报错
        return 0;
    x = S.data[S.top--]; //先出栈，指针再减1
    return 1;
}

int IE(SqStack S){
    if(S.top==-1) return 1;
    else return 0;
}

int Pipei(SqStack &S){
    char ch,c;
    int r;
    while((ch=getchar())!='#'){
            r=IE(S);
        switch(ch){
            case '(':case '[':case '{':Push(S,ch); printf("1");break;
            case ')':  r=IE(S); if(r){printf("2");return 0;} else{ Pop(S,c); printf("%c",c);if(c!='('){printf("3");return 0;}}
            case ']':if(r) return 0;Pop(S,c);if(c!='[') return 0; break;
            case '}':if(r) return 0;Pop(S,c);if(c!='{') return 0; break;
        }
    }
    printf("%c",S.data[S.top]);
    printf("%d",IE(S));
    if(IE(S))return 1;
    else return 0;
}

int main(){
    Stack s;
    Stack* S=&s;
    InitStack(*S);
    printf("%d",Pipei(*S));
    return 0;

}
