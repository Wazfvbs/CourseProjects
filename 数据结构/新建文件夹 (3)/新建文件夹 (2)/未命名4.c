#include<stdio.h> 
int main(){
	double a,s=0,sum;
	char b;
	scanf("%c%lf",&b,&a);
	switch(b){
		case 'A':s=19.99;break;
		case 'B':s=17.99;break;
		case 'C':s=15.99;break;
		case 'D':s=11.99;break;
	}
	if(s){
		sum=a*s;
		printf("%.2lf",sum);
	}else{
		printf("No available.");
	}
	return 0;
}
