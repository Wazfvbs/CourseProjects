#include<stdio.h> 
int main(){
	int a,b,h1,h2,m1,m2,hh,mm;
	scanf("%d %d",&a,&b);
	h1=a/100;
	h2=b/100;
	m1=a%100;
	m2=b%100;
	hh=h2-h1;
	if(m1>m2){
		hh-=1;
		mm=m2+60-m1;
	}else{
		mm=m2-m1;
	}
	printf("%2d:%2d",hh,mm);
	return 0;
}
