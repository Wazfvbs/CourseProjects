#define _CRT_SECURE_NO_WARNINGS//vs������һ��scanf�ſ���ʹ��
#include<iostream>
using namespace std;
 
int jie_cheng(int x) {//������x�Ľ׳�
	int sum = 1;
	for (int i = 1; i <= x; i++) {
		sum *= i;
	}return sum;//����sum
}
 
int main()
{
	int m, n, p;
	while(scanf("%d%d", &m, &n)==2){
		p = jie_cheng(m)/(jie_cheng(m-n)*jie_cheng(n));//�󷨼���
		printf("%d", p);
	}
	
	return 0;
}
