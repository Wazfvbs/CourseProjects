#include<stdio.h> 
int main(){
	double a[3],temp;
	int i,j;
	for(i=0;i<3;i++){
		scanf("%lf",&a[i]);
	}
	for(i=0;i<3;i++){
		for(j=i+1;j<3;j++){
			if(a[j]>a[i]){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(i=0;i<3;i++){
		printf("%.2lf ",a[i]);
	} 
	return 0;
}
