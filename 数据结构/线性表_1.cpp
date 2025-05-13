/*����һ�����Ա�����һ��һά�����е�ǰn������Ԫ��λ�á����дһ��˳���ĳ��򣬽�������Ա�ԭ�����á�

�ֱ��������ǰ��˳�������ú��˳�����˳����Ԫ������Ϊ���ͣ�

���룺������һ������n����ʾ˳���ĳ��ȣ�֮������n������

��������У�ÿ����֮����һ���ո�ָ���

��һ��Ϊԭ����˳����ڶ���Ϊ���ú��˳���*/\
/*����һ�����Ա�����һ��һά�����е�ǰn������Ԫ��λ�á����дһ��˳���ĳ��򣬽�������Ա�ԭ�����á�

�ֱ��������ǰ��˳�������ú��˳�����˳����Ԫ������Ϊ���ͣ�

���룺������һ������n����ʾ˳���ĳ��ȣ�֮������n������

��������У�ÿ����֮����һ���ո�ָ���

��һ��Ϊԭ����˳����ڶ���Ϊ���ú��˳���*/\
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef int ElemType;
//�ṹ��
typedef struct Seqlist
{
    ElemType elem[MaxSize];
    int length;
}SeqList;

//��ʼ��
int Init_SeqList(SeqList *L)
{
    L->length = 0;
    return 1;
}

SeqList* CreatList()
{
    SeqList* sq = (SeqList*)malloc(sizeof(SeqList));
    int i;
    scanf("%d", &(sq->length));
    for (i = 0; i < sq->length; i++) {
        scanf("%d", &(sq->elem[i]));
    }
    return sq;

}

//��λ����
int Locate_SeqList(SeqList* L, int x)
{
    int i=0;
    for (i = 0; i < L->length && L->elem[i] != x; i++);
    if(i>=L->length){
        printf("˳����в����ڸ�Ԫ�أ�\n");
        return 0;
    }
    else
        return i+1;
}

//����
int Insert_SeqList(SeqList *L,int i,int x)
{
    int j;
    if(L->length>=MaxSize)
    {
        printf("˳����������޷����в��������");
        return 0;
    }
    else if(i<=0||i>L->length+1)
    {
        printf("�����λ�ò���ȷ��");
        return 0;
    }
    //�����һ��Ԫ�ؿ�ʼ��һ��һ����������һλ����Ҫ�����Ԫ�������ռ�
    for(j=L->length-1;j>=i-1;j--)
    {
        L->elem[j+1]=L->elem[j];
    }
    //�ڵ�i��Ԫ��֮ǰ������ǰѴ�i��ʼ��Ԫ�������ƣ�Ȼ��ֵ����i��Ԫ�أ��������о���i-1��
    L->elem[i-1]=x;
    L->length++; //������֮�����鳤��+1
    return 1;
}
//����
int Insert(SeqList* L, int x) {
    int i;
    if (L->length >= MaxSize)
    {
        printf("˳����������޷����в��������");
        return 0;
    }
    else
    {
        L->elem[L->length] = x;
        L->length++;
        return 1;
    }
}

//����ɾ��˳���Ԫ�غ�����ɾ����i��Ԫ��
int Delete_SeqList(SeqList *L,int i)
{
    int j;
    if((i<1)||(i>L->length))//�Ͳ�����һ�����ж�����
    {
        printf("ɾ��λ�ò���ȷ��");
        return 0;
    }
    //ɾ����i��Ԫ�ؾ��Ǵӵ�i��Ԫ�ؿ�ʼһ��һ���شӺ���ǰ����
    for(j=i;j<L->length;j++)
    {
        L->elem[j-1]=L->elem[j];
    }
    L->length--;//���鳤��-1
    return 1;
}

//��ӡ
int PrintList(SeqList *L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",L->elem[i]);
    }
    printf("\n");
    return 1;
}
//����
int Reverse(SeqList* L) {
    int i,temp;
    for (i = 0; i < (L->length )/2; i++) {
        temp=L->elem[i];
        L->elem[i] = L->elem[L->length - 1 - i];
        L->elem[L->length - 1 - i] = temp;
    }
    return 1;
}

int main(){
    SeqList L;
    Init_SeqList(&L);
    int n, i, m;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        Insert(&L, m);
    }
    PrintList(&L);
    Reverse(&L);
    PrintList(&L);
    return 0;
}

