#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

void InitList(SqList &L){
    L.length=0;
}

SqList *CreateList(){
    SqList *L=new SqList;
    scanf("%d",&L->length);
    int i;
    for(i=0;i<L->length;i++){
        scanf("%d",&L->data[i]);
    }
    return L;
}

int InsertList(SqList &L,int i,ElemType e){
    if(i<0||i>L.length) return 0;
    if(L.length+1>MAXSIZE) return 0;
    int j;
    for(j=L.length-1;j>=i-1;j--){
        L.data[j+1]=L.data[j];

    }
    L.data[i-1]=e;
    L.length++;
    return 1;
}


void PrintList(SqList L){
    int i;
    for(i=0;i<L.length;i++){
        printf("%d ",L.data[i]);

    }
}

int main(){
    SqList l;
    SqList *L=&l;
    InitList(*L);
    L=CreateList();
    PrintList(*L);
    InsertList(*L,4,6);
    PrintList(*L);
    return 0;


}
