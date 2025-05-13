#include<stdio.h> 
int main(){
	char a[5];
	int i;
	for(i=0;i<5;i++){
		scanf("%c",&a[i]);
	}
	for(i=0;i<5;i++){
		if(a[i]>=97&&a[i]<=119){
			a[i]+=3;
		}else if(a[i]>=120&&a[i]<=122){
			a[i]-=23;
		}
	}
	for(i=0;i<5;i++){
		printf("%c",&a[i]);
	}
	return 0;
}
