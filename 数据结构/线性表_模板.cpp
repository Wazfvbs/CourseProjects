#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
    int length;
}SqList;

SqList *CreateList(){
    SqList *sq = new SqList;
    int i;
    scanf("%d",&sq->length);
    for(i=0;i<sq->length;i++){
        scanf("%d",&sq->data[i]);
    }
    return sq;
}


int InsertList(SqList& L, int i, ElemType e) {
    if (i<1 || i>L.length + 1)
        return 0;
    if (L.length >= MaxSize)
        return 0;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return 1;
}

int DeleteList(SqList& L, int i, ElemType& e) {
    //���㷨ʵ��ɾ��˳���L�е�i��λ�õ�Ԫ��
    if (i<1 || i>L.length) //�ж�i�ķ�Χ�Ƿ���Ч
        return 0;
    e = L.data[i - 1]; //����ɾ����Ԫ�ظ�ֵ��e
    for (int j = i; j < L.length; j++)//����i��λ��֮���Ԫ��ǰ��
        L.data[j - 1] = L.data[j];
    L.length--; //���Ա��ȼ�1
    return 1;
}

int LocateElem(SqList L, ElemType e) {
    //ʵ�ֲ���˳�����ֵΪe��Ԫ��
    int i;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1; //������λ��i+1
    return 0; //�˳�ѭ����˵������ʧ��
}

void PrintList(SqList L){
    int i;
    for(i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
}

void ReverseList(SqList &L) {
    int i, temp;
    for (i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}

int main() {
    SqList l;
    SqList *L=&l;
    L= CreateList();
    PrintList(*L);
    printf("\n");
    ReverseList(*L);
    PrintList(*L);
    return 0;

}
