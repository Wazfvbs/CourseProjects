#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct Node {
    ElemType data;
    struct Node* next;
}Stack, * LinkStack;

int InitStack(LinkStack& S) {
    S = NULL;
    return 1;
}

Stack* CreateNode(ElemType e) {
    Stack* newNode = new Stack;
    newNode->data = e;
    newNode->next = NULL;
    return newNode;
}

int Push(LinkStack& S, ElemType e) {
    Stack* newNode = CreateNode(e);
    newNode->next = S;
    S = newNode;
    return 1;
}

int Pop(LinkStack& S, ElemType& e) {
    Stack* p;
    if (S == NULL) return 0;
    else {
        p = S;
        e = p->data;
        S = S->next;
        free(p);
        return 1;
    }
}

int IE(LinkStack S) {
    if (S == NULL) return 1;
    else return 0;
}

ElemType Gettop(LinkStack S) {
    ElemType e;
    e = S->data;
    return e;

}

int SHURU(LinkStack& S) {
    char ch, c;
    int r;

    while (ch = getchar() != '#') {
        if (ch == '(' || ch == '[' || ch == '{') Push(S, ch);
        else if (ch == ')') {
            r = IE(S);
            if (r) return 0;
            else {
                Pop(S, c);
                if (c != '(') return 0;
            }
        }
        else if (ch == ']') {
            r = IE(S);
            if (r) return 0;
            else {
                Pop(S, c);
                if (c != '([') return 0;
            }
        }
        else if (ch == '}') {
            r = IE(S);
            if (r) return 0;
            else {
                Pop(S, c);
                if (c != '{') return 0;
            }
        }
    }
    r = IE(S);
    if (r) return 1;
    else return 0;
}

int main() {

    LinkStack S;
    InitStack(S);
    int r;
    r = SHURU(S);
    printf("%d", r);
    return 0;

}

