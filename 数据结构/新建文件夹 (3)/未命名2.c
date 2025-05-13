#include<stdio.h>
int Jiecheng(int m){
	int i,sum=1;
	for(i=1;i<=m;i++){
		sum*=i;
	}
	return sum;
}
int Zuhe(int m,int n){
	int sum;
	sum=(Jiecheng(m))/(Jiecheng(m-n)*Jiecheng(n));
	return sum;
}
int main(){
	int  a,b,c,d,e,f,g;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	e=Zuhe(c+d-a-b,c-a)*Zuhe(e+f-c-d,e-c);
	printf("%d",e);
	return 0;
} 
