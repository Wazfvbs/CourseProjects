#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1
typedef char ElemType;
typedef struct Stack {
    ElemType data;
    struct Stack* next;
}StackNode, * LinkStack;
int InitStack(LinkStack& S) {
    S = NULL;
    return 1;
}
int Push(LinkStack& S, ElemType e) {
    StackNode* p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return 1;
}

int Pushf(LinkStack& S, double e) {
    StackNode* p = new StackNode;
    p->data = e;
    p->next = S;
    S = p;
    return 1;
}



int Pop(LinkStack& S, ElemType& e) {
    if (S == NULL) return 0;
    else {
        StackNode* p = S;
        e = S->data;
        S = S->next;
        delete(p);
        return 1;
    }
}



int Popf(LinkStack& S, double &e) {
    if (S == NULL) return 0;
    else {
        StackNode* p = S;
        e = S->data;
        S = S->next;
        delete(p);
        return 1;
    }
}

int Youxianji1(char ch) {
    switch (ch) {
    case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/':return 2;
    case '(': return 3;
    }
}

int Youxianji2(char ch) {
    switch (ch) {
    case ')': case '(': return 0;
    case '+': case '-': return 1;
    case '*': case '/':return 2;
    case '0':return -1;
    }
}


ElemType Get(LinkStack S) {
    ElemType e;
    if (S) {
        e = S->data;
        return e;
    }
    else return 0;

}

double Getf(LinkStack S) {
    double e;
    if (S) {
        e = S->data;
        return e;
    }
    else return 0;

}

int main() {
    char ch, top;
    double x1=0,x2=0,x3=0,a=0,b=0;
    LinkStack S1, S2;
    InitStack(S1);//+-
    InitStack(S2);//123
    while (ch = getchar() != '#') {
        top = Get(S1);
        if (ch >= '0' && ch <= '9') {//12xianyaru
            Pushf(S2, ch - '\0');
        }
        else {//+-
            a = Youxianji1(ch);
            b = Youxianji2(Get(S1));
            if (a > b) {
                Push(S1, ch);
            }
            else {
                if (a == b == 0) {
                    Pop(S1, top);
                }
                else {
                    switch (top) {
                    case '+':
                        Pop(S1, top); Popf(S2, x1); Popf(S2, x2); x3 = x1 + x2; Pushf(S2, x3); break;
                    case '-':
                        Pop(S1, top); Popf(S2, x1); Popf(S2, x2); x3 = x1 - x2; Pushf(S2, x3); break;
                    case '*':
                        Pop(S1, top); Popf(S2, x1); Popf(S2, x2); x3 = x1 * x2; Pushf(S2, x3); break;
                    case '/':
                        Pop(S1, top); Popf(S2, x1); Popf(S2, x2); x3 = x1 / x2; Pushf(S2, x3); break;
                    }
                }
            }
        }

    }
    while (S1) {
        Pop(S1, top);
        switch (top) {
        case '+':
            Pop(S1, top); Popf(S2, x1); Popf(S2, x2); x3 = x1 + x2; Pushf(S2, x3); break;
        case '-':
            Pop(S1, top); Popf(S2, x1); Popf(S2, x2); x3 = x1 - x2; Pushf(S2, x3); break;
        case '*':
            Pop(S1, top); Popf(S2, x1); Popf(S2, x2); x3 = x1 * x2; Pushf(S2, x3); break;
        case '/':
            Pop(S1, top); Popf(S2, x1); Popf(S2, x2); x3 = x1 / x2; Pushf(S2, x3); break;
        }

    }
    int x;
    Pushf(S2, x);
    printf("%d", x);
    return 0;

}

