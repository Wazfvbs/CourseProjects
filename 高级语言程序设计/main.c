#include <stdio.h>
int main(){
	int n,i;
	FILE* fp;
	int a[300],b[300]; 
	fp=fopen("test01.txt","w");
	while((scanf("%d",&n))!=0){
		for(i=0;i<n;i++){
			fgets(a,300,stdin);
			fputs(a,fp);
		}
	}
	fclose(fp);
    fp=fopen("test01.txt","r");
    while(fgets(b,300,fp)!=NULL)
    printf("%s",b);
    return 0;

	
} 
