#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#define maxnum 1000
using namespace std;
typedef struct node
{
    int x,y;//��ͼ����,�ӣ�1��1����ʼ
}mapnode;

int flag=0;//�ж��ܷ��յ�
int m,n;//��ͼ����m����n
int **map;//��ͼ��Ϣ,0�����ߣ�1������
int **visited;//������Ϣ��0��ʾδ���ʣ�1��ʾ�Ѿ����ʹ�
int minsize;//���·������
stack<mapnode> s,mins;//��ȱ���������·������·�������·����ջ
queue<mapnode> q;
mapnode in, out,**pre;//��㡢�յ㡢��ǰ���ǰһ���� ������
int movex[4]={0,1,0,-1};
int movey[4]={-1,0,1,0};//��Ӧ���¡��ҡ����ƶ�



void createmap(int m, int n);//�����ͼ��Ϣ,����������Ϣ
void visited0();// ��շ�����Ϣ
void deleteinfo(int m, int n);//ɾ������Ŀռ�
void outputmap(int m, int n); // �����ͼ

int pass(mapnode p);// �����Ƿ������
int BFSminroad(queue<mapnode> &q);//��ȱ������ǵݹ������·��,��visited��·������

void createmap(int m, int n) // �����ͼ��Ϣ,����������Ϣ
{
    int i, j;
    map = new int *[m+1];//m+1��
    visited = new int *[m + 1];
    for (i = 0; i <= m; i++){
        map[i] = new int[n+1];// m+1��n+1��
        visited[i] = new int[n+1]; 
    }
    for (i = 1; i <= m; i++)
      for (j = 1; j <= n; j++){
        cin >> map[i][j];//�����ͼ��Ϣ
      }
    for (i = 1; i <= m; i++)//��ʼ����������Ϊ0 
     for (j = 1; j <= n; j++)
         visited[i][j] = 0;
}

void visited0()// ��շ�����Ϣ
{
    int i, j;
    for (i = 1; i <= m; i++)//��ʼ����������Ϊ0 
     for (j = 1; j <= n; j++)
         visited[i][j] = 0;
}

void deleteinfo(int m,int n)
{//ɾ������Ŀռ�
    int i;
    for (i = 0; i <= m; i++)//��0��ʼ��m+1��ȫ�ͷ�
    {
        delete[] map[i];//�ͷ�һ��ָ��
        delete[] visited[i];
    }
    delete[] map;//�ͷŶ���ָ��
    delete[] visited;
}

void outputmap(int m,int n)//�����ͼ
{
    cout << endl;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(map[i][j]<2)
                cout << map[i][j] << ' ';
            else if(map[i][j]==2)//���
                cout << "*"<<' ';
            else if(map[i][j]==3)//�յ�
                cout << "#"<<' ';
        }
        cout << endl;
    }
    cout << endl;
    //cout << "ע����ͼ�����(1,1)��ʼ" << endl;
    cout << endl;
}

int pass(mapnode  p)//�����Ƿ������
{
    if (p.x<1 || p.x>m)//x���곬���Թ���Χ
    {
		return 0;
	}
	else if (p.y<1 || p.y>n)//y���곬���Թ���Χ
    {	
		return 0;
	}
	else if (!(visited[p.x][p.y] == 0))//�Ѿ��߹��õ�
    {
		return 0;
	}
	else if (map[p.x][p.y] == 1)//�õ����ϰ�
    {
		return 0;
	}
	else
        return 1; //������
}

int BFSminroad(queue<mapnode> &q)
{//��ȱ������ǵݹ������·��,��visited��·������
    int i, j, temp;
    visited0();//��շ�����Ϣ
    pre = new mapnode *[m + 1]; // m+1��
    for (i = 0; i <= m; i++)
    {
        pre[i] = new mapnode[n+1];// m+1��n+1�� 
    }
    q.push(out);//�յ�����У����յ��������·��
    pre[out.x][out.y].x= 0;
    pre[out.x][out.y].y= 0;//�յ��ǰ����Ϊ��0��0��
    mapnode p,next;
    while(!q.empty())
    {
        p = q.front();//ȡ������Ԫ��
        q.pop();// ������Ԫ�س�����
        if(p.x==in.x&&p.y==in.y)//����Ϊ���ʱ���ҽ���
        {//�ܵ����յ�,���·���ͳ���
            flag = 1;//�ܵ����յ��־
            i = in.x;
            j = in.y; 
            while (i != 0 && j != 0)
            {
                printf("(%d, %d)", i, j);
                temp = i;
                i = pre[i][j].x;
                j = pre[temp][j].y;
                if (i != 0 && j != 0)
                {
                    cout << "->";
                }
            }
            cout << endl;
            cout << "���·������Ϊ��" << visited[in.x][in.y] << endl;
            for (i = 0; i <= m; i++)//��0��ʼ��m+1��ȫ�ͷ�
            {
                delete[] pre[i];
            }
            delete[] pre;
            while(!q.empty())//��ն��� 
            {
            	q.pop();
			}
            return 1;
        }
        for (i = 0; i < 4; i++)//ѭ������̽����Χ4�������ϵĵ�
        {
            next.x = p.x + movex[i];
            next.y = p.y + movey[i];
            //printf("\n%d:%d,%d\n", i, next.x, next.y);
            if (pass(next)&&(next.x!=out.x||next.y!=out.y))// nextΪp����һ����
            {
                visited[next.x][next.y] = visited[p.x][p.y] + 1; // ���ʶ�Ӧ��,����+1
                q.push(next);
                pre[next.x][next.y].x = p.x;
                pre[next.x][next.y].y = p.y;
            }
        }
    }
    cout << "�Ҳ���������յ���·��,�������·��"<<endl;//while���������п�Ҳû���յ�
    for (i = 0; i <= m; i++) // ��0��ʼ��m+1��ȫ�ͷ�
    {
        delete[] pre[i];
    }
    delete[] pre;
    while(!q.empty())//��ն��� 
    {
        q.pop();
	}
    return 0;
}

int main()
{
    int flag2 = 1, flag3 = 1;
    int x;
    char y;
    while(flag2==1)
    {
        cout << "�������Թ�������������:" << endl;
        cin >> m >> n; // �Թ���һ��������Ϊ��1,1��
        cout << "�������Թ�����Ϣ(0��ʾ��ͨ��,1��ʾ�ϰ���):" << endl;
        createmap(m, n); // �����ͼ��Ϣ
        cout << "ע����ͼ�����(1,1)��ʼ" << endl;
        cout << "�����������յ�:" << endl;
        while(flag3==1)//��������յ㣬����ѭ��
        {
            cin >> in.x >> in.y;
            cin >> out.x >> out.y;
            if(in.x<1||in.x>m||in.y<1||in.y>n||out.x<1||out.x>m||out.y<1||out.y>n||(in.x==out.x&&in.y==out.y))
            {//��㲻�ܵ����յ㣬����յ㲻��Ϊǽ
                system("cls");
                cout << "������ĵ�ͼ����" << endl
                     << "0��ʾ��ͨ��,1��ʾ�ϰ���" << endl;
                outputmap(m, n);
                cout<<"����յ����겻����,����������:"<<endl;
                flag3 = 1;
                continue;//������һ�ֶ���ѭ��,������������յ�
            }
            else if (map[in.x][in.y] == 1 || map[out.x][out.y] == 1)
            {
            	system("cls");
                cout << "������ĵ�ͼ����" << endl
                     << "0��ʾ��ͨ��,1��ʾ�ϰ���" << endl;
                outputmap(m, n);
                cout<<"����յ����겻����,����������:"<<endl;
                flag3 = 1;
                continue;//������һ�ֶ���ѭ��,������������յ�
			}
            else
            {
                map[in.x][in.y] = 2;   // ���
                map[out.x][out.y] = 3; // �յ�
            }
            system("cls");
            cout << "������ĵ�ͼ����" << endl
                 << "0��ʾ��ͨ��,1��ʾ�ϰ���,*Ϊ��㣬#Ϊ�յ㣬" << endl;
            outputmap(m, n);   // ��ӡ��ͼ
            printf("��(%d,%d)��(%d,%d)��һ����̵�·������:\n",in.x,in.y,out.x,out.y);
            x = BFSminroad(q); // ������·��
             
        }
        
    }
    return 0;
}

/*
1 0 1 1
1 0 0 0
1 0 1 0
1 0 0 0
      
1 2
2 4

1 0 1 1 1 1
1 0 0 0 0 1
1 0 1 1 0 1
1 0 1 1 0 0 
1 0 1 1 0 1
1 0 0 0 0 1
   
1 2
4 6
*/
