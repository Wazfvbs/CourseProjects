#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>
#define maxnum 1000
using namespace std;
typedef struct node
{
    int x,y;//地图坐标,从（1，1）开始
}mapnode;

int flag=0;//判断能否到终点
int m,n;//地图的行m与列n
int **map;//地图信息,0可以走，1不能走
int **visited;//访问信息，0表示未访问，1表示已经访问过
int minsize;//最短路径长度
stack<mapnode> s,mins;//深度遍历求所有路径，存路径和最短路径的栈
queue<mapnode> q;
mapnode in, out,**pre;//起点、终点、当前点的前一个点 的坐标
int movex[4]={0,1,0,-1};
int movey[4]={-1,0,1,0};//对应左、下、右、上移动



void createmap(int m, int n);//输入地图信息,创建访问信息
void visited0();// 清空访问信息
void deleteinfo(int m, int n);//删除申请的空间
void outputmap(int m, int n); // 输出地图

int pass(mapnode p);// 检查点是否可以走
int BFSminroad(queue<mapnode> &q);//广度遍历，非递归求最短路径,用visited存路径长度

void createmap(int m, int n) // 输入地图信息,创建访问信息
{
    int i, j;
    map = new int *[m+1];//m+1行
    visited = new int *[m + 1];
    for (i = 0; i <= m; i++){
        map[i] = new int[n+1];// m+1行n+1列
        visited[i] = new int[n+1]; 
    }
    for (i = 1; i <= m; i++)
      for (j = 1; j <= n; j++){
        cin >> map[i][j];//输入地图信息
      }
    for (i = 1; i <= m; i++)//初始化访问数组为0 
     for (j = 1; j <= n; j++)
         visited[i][j] = 0;
}

void visited0()// 清空访问信息
{
    int i, j;
    for (i = 1; i <= m; i++)//初始化访问数组为0 
     for (j = 1; j <= n; j++)
         visited[i][j] = 0;
}

void deleteinfo(int m,int n)
{//删除申请的空间
    int i;
    for (i = 0; i <= m; i++)//从0开始，m+1个全释放
    {
        delete[] map[i];//释放一级指针
        delete[] visited[i];
    }
    delete[] map;//释放二级指针
    delete[] visited;
}

void outputmap(int m,int n)//输出地图
{
    cout << endl;
    int i, j;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
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
    //cout << "注：地图坐标从(1,1)开始" << endl;
    cout << endl;
}

int pass(mapnode  p)//检查点是否可以走
{
    if (p.x<1 || p.x>m)//x坐标超出迷宫范围
    {
		return 0;
	}
	else if (p.y<1 || p.y>n)//y坐标超出迷宫范围
    {	
		return 0;
	}
	else if (!(visited[p.x][p.y] == 0))//已经走过该点
    {
		return 0;
	}
	else if (map[p.x][p.y] == 1)//该点是障碍
    {
		return 0;
	}
	else
        return 1; //可以走
}

int BFSminroad(queue<mapnode> &q)
{//广度遍历，非递归求最短路径,用visited存路径长度
    int i, j, temp;
    visited0();//清空访问信息
    pre = new mapnode *[m + 1]; // m+1行
    for (i = 0; i <= m; i++)
    {
        pre[i] = new mapnode[n+1];// m+1行n+1列 
    }
    q.push(out);//终点入队列，从终点往起点找路径
    pre[out.x][out.y].x= 0;
    pre[out.x][out.y].y= 0;//终点的前点设为（0，0）
    mapnode p,next;
    while(!q.empty())
    {
        p = q.front();//取队列首元素
        q.pop();// 队列首元素出队列
        if(p.x==in.x&&p.y==in.y)//队首为起点时查找结束
        {//能到达终点,输出路径和长度
            flag = 1;//能到达终点标志
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
            cout << "最短路径长度为：" << visited[in.x][in.y] << endl;
            for (i = 0; i <= m; i++)//从0开始，m+1个全释放
            {
                delete[] pre[i];
            }
            delete[] pre;
            while(!q.empty())//清空队列 
            {
            	q.pop();
			}
            return 1;
        }
        for (i = 0; i < 4; i++)//循环遍历探测周围4个方向上的点
        {
            next.x = p.x + movex[i];
            next.y = p.y + movey[i];
            //printf("\n%d:%d,%d\n", i, next.x, next.y);
            if (pass(next)&&(next.x!=out.x||next.y!=out.y))// next为p的下一个点
            {
                visited[next.x][next.y] = visited[p.x][p.y] + 1; // 访问对应点,距离+1
                q.push(next);
                pre[next.x][next.y].x = p.x;
                pre[next.x][next.y].y = p.y;
            }
        }
    }
    cout << "找不到起点与终点间的路径,故无最短路径"<<endl;//while结束，队列空也没到终点
    for (i = 0; i <= m; i++) // 从0开始，m+1个全释放
    {
        delete[] pre[i];
    }
    delete[] pre;
    while(!q.empty())//清空队列 
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
        cout << "请输入迷宫的行数和列数:" << endl;
        cin >> m >> n; // 迷宫第一个点坐标为（1,1）
        cout << "请输入迷宫的信息(0表示可通过,1表示障碍物):" << endl;
        createmap(m, n); // 输入地图信息
        cout << "注：地图坐标从(1,1)开始" << endl;
        cout << "请输入起点和终点:" << endl;
        while(flag3==1)//输入起点终点，二级循环
        {
            cin >> in.x >> in.y;
            cin >> out.x >> out.y;
            if(in.x<1||in.x>m||in.y<1||in.y>n||out.x<1||out.x>m||out.y<1||out.y>n||(in.x==out.x&&in.y==out.y))
            {//起点不能等于终点，起点终点不能为墙
                system("cls");
                cout << "你输入的地图如下" << endl
                     << "0表示可通过,1表示障碍物" << endl;
                outputmap(m, n);
                cout<<"起点终点坐标不符合,请重新输入:"<<endl;
                flag3 = 1;
                continue;//进入下一轮二级循环,重新输入起点终点
            }
            else if (map[in.x][in.y] == 1 || map[out.x][out.y] == 1)
            {
            	system("cls");
                cout << "你输入的地图如下" << endl
                     << "0表示可通过,1表示障碍物" << endl;
                outputmap(m, n);
                cout<<"起点终点坐标不符合,请重新输入:"<<endl;
                flag3 = 1;
                continue;//进入下一轮二级循环,重新输入起点终点
			}
            else
            {
                map[in.x][in.y] = 2;   // 起点
                map[out.x][out.y] = 3; // 终点
            }
            system("cls");
            cout << "你输入的地图如下" << endl
                 << "0表示可通过,1表示障碍物,*为起点，#为终点，" << endl;
            outputmap(m, n);   // 打印地图
            printf("从(%d,%d)到(%d,%d)的一条最短的路径如下:\n",in.x,in.y,out.x,out.y);
            x = BFSminroad(q); // 输出最短路径
             
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
