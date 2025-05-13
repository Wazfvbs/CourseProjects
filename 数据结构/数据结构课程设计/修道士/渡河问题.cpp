#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


int n,m,c;

typedef struct {
	int xds;
	int ymr;
	int zt;
} DataType;
DataType fa[5000];

typedef struct Node {
	int dest;                            //�ڽӱ�Ļ�ͷ������
	struct Node *next;
} Edge;                               //�ڽӱ�����Ľ��ṹ��

//����Ԫ�� 
typedef struct {
	DataType  data;                    //�������Ԫ��
	int       sorce;                   //�ڽӱ�Ļ�β������
	Edge      *adj;                    //�ڽӱߵ�ͷָ��
	int       pre;                     //ָ��˵�ĵ�����
} AdjLHeight;                          //���������Ԫ�����ͽṹ��
//ͼ�ṹ���� 
typedef struct {
	AdjLHeight a[10000];                    //�ڽӱ�����
	int numOfVerts;                        //������
	int numOfEdges;                        //�߸���
} AdjLGraph;                               //�ڽӱ�ṹ��

void AdjInitiate(AdjLGraph *G) {//ͼ�ĳ�ʼ��
	int i;
	G->numOfEdges=0;
	G->numOfVerts=0;
	for(i=0; i<10000; i++) {
		G->a[i].sorce=i;              
		G->a[i].adj=NULL;                
		G->a[i].data.zt=-1;
		G->a[i].pre=-1;
	}
}
//������ 
void InsertVertex(AdjLGraph *G, int i, DataType vertex) {  
	if( i>=0 && i<10000 ) {
		G->a[i].data.xds=vertex.xds;
		G->a[i].data.ymr=vertex.ymr;
		G->a[i].data.zt=vertex.zt;
		G->numOfVerts++;
	} else printf("���Խ��!\n");
}
void InsertEdge(AdjLGraph *G,int v1,int v2) {    
	Edge *p;
	if(v1<0||v1>=G->numOfVerts||v2<0||v2>G->numOfVerts) {
		printf("����v1��v2Խ�����!");
		exit(0);
	}
	p=new Edge;
	p->dest=v2;
	p->next=G->a[v1].adj;
	G->a[v1].adj=p;
	G->numOfEdges++;
}
void AdjDestroy(AdjLGraph *G)  {
	int i;
	Edge *p,*q;
	for(i=0; i<G->numOfVerts; i++) {
		p=G->a[i].adj;
		while(p!=NULL) {
			q=p->next;
			free(p);
			p=q;
		}
	}
}
int jiancha(DataType x) {
	if ((x.xds>=x.ymr||x.xds==0)&&((n-x.xds)>=(n-x.ymr)||x.xds==n)&&x.xds>=0&&x.xds<=n&&x.ymr>=0&&x.ymr<=n)
		return 1;
	else
		return 0;
}
int findfa(DataType x) {
	int i=0,a,b,t=0;
	if(x.zt) {
		a=0;
		b=c-a;
		while (a+b>=1) {
			t++;
			while (b>=0) {
				fa[i].xds=a;
				fa[i].ymr=b;
				i++;
				a++;
				b--;
			}
			a=0;
			b=c-a-t;
		}
	} else {
		a=1;
		b=0;
		t=0;
		while (a+b<=c) {
			t++;
			while (a>=0) {
				fa[i].xds=a*(-1);
				fa[i].ymr=b*(-1);
				i++;
				a--;
				b++;
			}
			a=fa[0].xds*(-1)+t;
			b=0;
		}
	}
	return i;
}
int print(AdjLGraph *p,int g) {
	DataType b[1000];
	int i=0;
	while (g!=-1) {
		b[i++]=p->a[g].data;
		g=p->a[g].pre;
	}
	while ((--i)>-1) {
		printf("( %d %d %d )",b[i].xds,b[i].ymr,b[i].zt);
		if (!(b[i].xds==0&&b[i].ymr==0&&b[i].zt==0)) {
			if (b[i].zt==1)
				printf("  �� (%d %d)  �� (%d %d 0)\n",b[i].xds-b[i-1].xds,b[i].ymr-b[i-1].ymr,b[i-1].xds,b[i-1].ymr);
			else
				printf("  �� (%d %d)  �� (%d %d 1)\n",(b[i].xds-b[i-1].xds)*(-1),(-1)*(b[i].ymr-b[i-1].ymr),b[i-1].xds,b[i-1].ymr);
		} else
			printf("\n");
	}
	printf("\n");
	return 1;
}
void work(AdjLGraph *p) {
	DataType tem;
	int i,flag1,g=0,j,count=0,k=0,t;
	while (p->a[k].data.zt!=-1) {
		j=findfa(p->a[k].data);
		for (i=0; i<j; i++) {
			tem.xds=p->a[k].data.xds-fa[i].xds;
			tem.ymr=p->a[k].data.ymr-fa[i].ymr;
			tem.zt=1-p->a[k].data.zt;
			if (jiancha(tem)) {
				flag1=1;
				t=k;
				while (t!=-1) {
					if(tem.xds==p->a[t].data.xds&&tem.ymr==p->a[t].data.ymr&&tem.zt==p->a[t].data.zt) {
						flag1=0;
						break;
					}
					t--;
				}
				if(flag1==1) {
					g++;
					p->a[g].pre=k;
					InsertVertex(p,g,tem);
					InsertEdge(p,k,g);
					if (tem.xds==0&&tem.ymr==0&&tem.zt==0) {
						count++;
						print(p,g);
					}
				}
			}
		}
		k++;
	}
	if (count==0)
		printf("���ܶɺ�\n");
	else printf("�ɺӳɹ�!\n��%d�ֶɺӷ���",count);
}
int main() {
	AdjLGraph G;
	DataType first;
	printf("                           3.�ɺ�����\n");
	printf("�޵�ʿ����N\tҰ������M\t���ɳ�����C:");
	scanf("%d%d%d",&n,&m,&c) ;
	AdjInitiate(&G);
	first.xds=n;
	first.ymr=m;
	first.zt=1;
	InsertVertex(&G, 0, first);
	work(&G);
	AdjDestroy(&G);
	return 0;
}
