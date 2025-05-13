#define _CRT_SECURE_NO_WARNINGS//vs加上这一行scanf才可以使用
#include<iostream>
using namespace std;
 
int jie_cheng(int x) {//用于求x的阶乘
	int sum = 1;
	for (int i = 1; i <= x; i++) {
		sum *= i;
	}return sum;//返回sum
}
 
int main()
{
	int m, n, p;
	while(scanf("%d%d", &m, &n)==2){
		p = jie_cheng(m)/(jie_cheng(m-n)*jie_cheng(n));//求法计算
		printf("%d", p);
	}
	
	return 0;
}
