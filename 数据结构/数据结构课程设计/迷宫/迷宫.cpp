#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#define maxnum 1000
using namespace std;
typedef struct node {
	int x,y;//��ͼ����,�ӣ�1��1����ʼ
} mapnode;

int movex[4]= {0,1,0,-1};
int movey[4]= {-1,0,1,0};
int m,n;
int **map;
int **visited;
queue<mapnode> q;
mapnode in, out,**pre;

void createmap(int m, int n){
	int i, j;
	map = new int *[m+1];
	visited = new int *[m + 1];
	for (i = 0; i <= m; i++){
		map[i] = new int[n+1];
		visited[i] = new int[n+1];
	}
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++){
			cin >> map[i][j];
		}
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			visited[i][j] = 0;
}

void visited0() {
	int i, j;
	for (i = 1; i <= m; i++)//��ʼ����������
		for (j = 1; j <= n; j++)
			visited[i][j] = 0;
}

void deleteinfo(int m,int n) {
	int i;
	for (i = 0; i <= m; i++) { 
		delete[] map[i];
		delete[] visited[i];
	}
	delete[] map;
	delete[] visited;
}

void outputmap(int m,int n) { //�����ͼ
	cout << endl;
	int i, j;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
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
}

int pass(mapnode  p) {
	if (p.x<1 || p.x>m) { //x���곬���Թ���Χ
		return 0;
	} else if (p.y<1 || p.y>n) { //y���곬���Թ���Χ
		return 0;
	} else if (!(visited[p.x][p.y] == 0)) { //�Ѿ��߹��õ�
		return 0;
	} else if (map[p.x][p.y] == 1) { //�õ����ϰ�
		return 0;
	} else
		return 1; //������
}
int flag=0;
int BFSminroad(queue<mapnode> &q) {
	int i, j, temp;
	visited0();
	pre = new mapnode *[m + 1]; 
	for (i = 0; i <= m; i++) {
		pre[i] = new mapnode[n+1];
	}
	q.push(out);
	pre[out.x][out.y].x= 0;
	pre[out.x][out.y].y= 0;
	mapnode p,next;
	while(!q.empty()) {
		p = q.front();
		q.pop();
		if(p.x==in.x&&p.y==in.y) {
			flag = 1;
			i = in.x;
			j = in.y;
			while (i != 0 && j != 0) {
				printf("(%d, %d)", i, j);
				temp = i;
				i = pre[i][j].x;
				j = pre[temp][j].y;
				if (i != 0 && j != 0) {
					cout << "->";
				}
			}
			cout << endl;
			cout << "���·������Ϊ��" << visited[in.x][in.y] << endl;
			for (i = 0; i <= m; i++) {
				delete[] pre[i];
			}
			delete[] pre;
			while(!q.empty()) {
				q.pop();
			}
			return 1;
		}
		for (i = 0; i < 4; i++) {
			next.x = p.x + movex[i];
			next.y = p.y + movey[i];
			if (pass(next)&&(next.x!=out.x||next.y!=out.y)) { 
				visited[next.x][next.y] = visited[p.x][p.y] + 1; 
				q.push(next);
				pre[next.x][next.y].x = p.x;
				pre[next.x][next.y].y = p.y;
			}
		}
	}
	cout << "�Ҳ���������յ���·��,�������·��"<<endl;
	for (i = 0; i <= m; i++) {
		delete[] pre[i];
	}
	delete[] pre;
	while(!q.empty()) { 
		q.pop();
	}
	return 0;
}

int main() {
	cout << "                           1.�Թ�����" << endl;
	int flag2 = 1, flag3 = 1;
	int x;
	char y;
	while(flag2==1) {
		cout << "�������Թ�������������:" << endl;
		cin >> m >> n;
		cout << "�������Թ�����Ϣ(0��ʾ��ͨ��,1��ʾ�ϰ���):" << endl;
		createmap(m, n);
		cout << "�����������յ�:" << endl;
		while(flag3==1) {
			cin >> in.x >> in.y;
			cin >> out.x >> out.y;
			if(in.x<1||in.x>m||in.y<1||in.y>n||out.x<1||out.x>m||out.y<1||out.y>n||(in.x==out.x&&in.y==out.y)) {
				cout << "������ĵ�ͼ����" << endl
				     << "0��ʾ��ͨ��,1��ʾ�ϰ���" << endl;
				outputmap(m, n);
				cout<<"����յ����겻����,����������:"<<endl;
				flag3 = 1;
				continue;
			} else if (map[in.x][in.y] == 1 || map[out.x][out.y] == 1) {
				cout << "������ĵ�ͼ����" << endl
				     << "0��ʾ��ͨ��,1��ʾ�ϰ���" << endl;
				outputmap(m, n);
				cout<<"����յ����겻����,����������:"<<endl;
				flag3 = 1;
				continue;
			} else {
				map[in.x][in.y] = 2;   // ���
				map[out.x][out.y] = 3; // �յ�
			}
			cout << "������ĵ�ͼ����" << endl
			     << "0��ʾ��ͨ��,1��ʾ�ϰ���,*Ϊ��㣬#Ϊ�յ㣬" << endl;
			outputmap(m, n);   // ��ӡ��ͼ
			printf("��(%d,%d)��(%d,%d)��һ����̵�·������:\n",in.x,in.y,out.x,out.y);
			x = BFSminroad(q); // ������·��

		}

	}
	return 0;
}
