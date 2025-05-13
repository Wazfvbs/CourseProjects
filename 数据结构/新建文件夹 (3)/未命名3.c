/*#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
long long int Jiecheng(long long int m){
	long long int i,sum=1;
	for(i=1;i<=m;i++){
		sum*=i;
	}
	return sum;
}
long long int Zuhe(long long int m,long long int n){
	long long int sum1=1,i,sum,sum2=1;
	for(i=n+1;i<=m;i++){
		sum1*=i;
	}
	for(i=1;i<=m-n;i++){
		sum2*=i;
	}
	sum=sum1/sum2;
	return sum;
}
long long int zuhe(long long int m,long long int n){
	long long int sum;
	sum=(Jiecheng(m))/(Jiecheng(m-n)*Jiecheng(n));
	return sum;
}
int main(){
	long long int m,n,i=0,j;
	while(scanf("%lld%lld",&m,&n)==2){
		printf("%lld ",Zuhe(m,n));
	}
	return 0;
} 
*/