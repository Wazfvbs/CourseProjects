#include<stdio.h>
int Jiecheng(int m){
	int i,sum=1;
	for(i=1;i<=m;i++){
		sum*=i;
	}
	return sum;
}
int Zuhe(int m,int n){
	int sum1=1,i,sum,sum2=1;
	for(i=n;i<=m;i++){
		sum1*=i;
	}
	sum=sum1/Jiecheng(m-n);
	return sum;
}
int zuhe(int m,int n){
	int sum;
	sum=(Jiecheng(m))/(Jiecheng(m-n)*Jiecheng(n));
	return sum;
}
int main(){
	int n,m,i=0,j;
	int a[100];
	scanf("%d",&n);
	while(n!=-1){
		m=zuhe(2*n,n)/(n+1);
		a[i]=m;
		i++;
		scanf("%d",&n);
	}
	for(j=0;j<i;j++){
		printf("%d ",a[j]);
	}
	return 0;
} 
