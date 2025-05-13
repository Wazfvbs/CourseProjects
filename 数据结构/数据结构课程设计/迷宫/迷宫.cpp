#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#define maxnum 1000
using namespace std;
typedef struct node {
	int x,y;//地图坐标,从（1，1）开始
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
	for (i = 1; i <= m; i++)//初始化访问数组
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

void outputmap(int m,int n) { //输出地图
	cout << endl;
	int i, j;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if(map[i][j]<2)
				cout << map[i][j] << ' ';
			else if(map[i][j]==2)//起点
				cout << "*"<<' ';
			else if(map[i][j]==3)//终点
				cout << "#"<<' ';
		}
		cout << endl;
	}
	cout << endl;
}

int pass(mapnode  p) {
	if (p.x<1 || p.x>m) { //x坐标超出迷宫范围
		return 0;
	} else if (p.y<1 || p.y>n) { //y坐标超出迷宫范围
		return 0;
	} else if (!(visited[p.x][p.y] == 0)) { //已经走过该点
		return 0;
	} else if (map[p.x][p.y] == 1) { //该点是障碍
		return 0;
	} else
		return 1; //可以走
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
			cout << "最短路径长度为：" << visited[in.x][in.y] << endl;
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
	cout << "找不到起点与终点间的路径,故无最短路径"<<endl;
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
	cout << "                           1.迷宫问题" << endl;
	int flag2 = 1, flag3 = 1;
	int x;
	char y;
	while(flag2==1) {
		cout << "请输入迷宫的行数和列数:" << endl;
		cin >> m >> n;
		cout << "请输入迷宫的信息(0表示可通过,1表示障碍物):" << endl;
		createmap(m, n);
		cout << "请输入起点和终点:" << endl;
		while(flag3==1) {
			cin >> in.x >> in.y;
			cin >> out.x >> out.y;
			if(in.x<1||in.x>m||in.y<1||in.y>n||out.x<1||out.x>m||out.y<1||out.y>n||(in.x==out.x&&in.y==out.y)) {
				cout << "你输入的地图如下" << endl
				     << "0表示可通过,1表示障碍物" << endl;
				outputmap(m, n);
				cout<<"起点终点坐标不符合,请重新输入:"<<endl;
				flag3 = 1;
				continue;
			} else if (map[in.x][in.y] == 1 || map[out.x][out.y] == 1) {
				cout << "你输入的地图如下" << endl
				     << "0表示可通过,1表示障碍物" << endl;
				outputmap(m, n);
				cout<<"起点终点坐标不符合,请重新输入:"<<endl;
				flag3 = 1;
				continue;
			} else {
				map[in.x][in.y] = 2;   // 起点
				map[out.x][out.y] = 3; // 终点
			}
			cout << "你输入的地图如下" << endl
			     << "0表示可通过,1表示障碍物,*为起点，#为终点，" << endl;
			outputmap(m, n);   // 打印地图
			printf("从(%d,%d)到(%d,%d)的一条最短的路径如下:\n",in.x,in.y,out.x,out.y);
			x = BFSminroad(q); // 输出最短路径

		}

	}
	return 0;
}
