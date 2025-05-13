#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -2

typedef struct QNode {//�����ӳ�Ա
	int  data;//���ݳ�Ա
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {//��ͷ��βָ��
	QueuePtr  front;
	QueuePtr  rear;
}LinkQueue;

void InitQueue(LinkQueue& Q)//��ʼ������
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));//���ٿռ�
	if (!Q.front) exit(OVERFLOW);//����ʧ�����˳�
	Q.front->next = NULL;
	//return 1;
}

int EnQueue(LinkQueue& Q, int e)//��Ӳ���
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (p == NULL) exit(OVERFLOW);
	p->data = e;  p->next = NULL;
	Q.rear->next = p;//��p�����β
	Q.rear = p;//��p��Ϊ��β
	return 1;
}

int DeQueue(LinkQueue& Q)//���Ӳ���
{
	QueuePtr p;
	int e;
	if (Q.front == Q.rear) {
		printf("����Ϊ��\n");
		return -1;
	}
	p = Q.front->next;//ͷָ��Ϊ��
	e = p->data;
	printf("%d ", e);
	Q.front->next = p->next;//ָ�����
	if (Q.rear == p) Q.rear = Q.front;//���pΪ��β
	free(p);//�ͷ�p
	return 1;
}



int main()
{
	int k;
	LinkQueue Q;
	InitQueue(Q);//��ʼ������
	scanf("%d", &k);
	while (k != 0)
	{
		EnQueue(Q, k);
		DeQueue(Q);
		scanf("%d", &k);
	}
	return 0;
}
