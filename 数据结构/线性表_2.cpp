/*键盘输入一组元素，以0做结束输入的标记，建立一个带头结点的单向链表（无序，且值域为整型）
遍历单向链表，显示相应元素。

输入：1 2 3 4 5 6 7 8 0

输出：1 2 3 4 5 6 7 8*/
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef int ElemType;
//结构体
typedef struct Seqlist
{
    ElemType elem[MaxSize];
    int length;
}SeqList;

//初始化
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

//定位查找
int Locate_SeqList(SeqList* L, int x)
{
    int i=0;
    for (i = 0; i < L->length && L->elem[i] != x; i++);
    if(i>=L->length){
        printf("顺序表中不存在该元素！\n");
        return 0;
    }
    else
        return i+1;
}

//插入
int Insert_SeqList(SeqList *L,int i,int x)
{
    int j;
    if(L->length>=MaxSize)
    {
        printf("顺序表已满，无法进行插入操作！");
        return 0;
    }
    else if(i<=0||i>L->length+1)
    {
        printf("插入的位置不正确！");
        return 0;
    }
    //从最后一个元素开始，一个一个地往后移一位，给要插入的元素留出空间
    for(j=L->length-1;j>=i-1;j--)
    {
        L->elem[j+1]=L->elem[j];
    }
    //在第i个元素之前插入就是把从i开始的元素往后移，然后赋值给第i个元素，在数组中就是i-1了
    L->elem[i-1]=x;
    L->length++; //插入完之后数组长度+1
    return 1;
}
//插入
int Insert(SeqList* L, int x) {
    int i;
    if (L->length >= MaxSize)
    {
        printf("顺序表已满，无法进行插入操作！");
        return 0;
    }
    else
    {
        L->elem[L->length] = x;
        L->length++;
        return 1;
    }
}

//定义删除顺序表元素函数，删除第i个元素
int Delete_SeqList(SeqList *L,int i)
{
    int j;
    if((i<1)||(i>L->length))//和插入是一样的判断条件
    {
        printf("删除位置不正确！");
        return 0;
    }
    //删除第i个元素就是从第i个元素开始一个一个地从后向前覆盖
    for(j=i;j<L->length;j++)
    {
        L->elem[j-1]=L->elem[j];
    }
    L->length--;//数组长度-1
    return 1;
}

//打印
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
//逆置
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
    int n;
    scanf("%d", &n);
    while (n != 0) {
        Insert(&L, n);
        scanf("%d",&n);
    }
    PrintList(&L);
    return 0;
}
