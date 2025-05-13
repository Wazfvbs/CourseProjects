#include <bits/stdc++.h>
using namespace std;
int main()
{
    FILE *fp,*fa;
    int n,i;
    char a[300][300],b[300];
    scanf("%d",&n);
    while(n!=0){
        fp=fopen("text01.txt","a");
    	getchar();
    	for(i=0;i<n;i++) gets(a[i]);
    	for(i=0;i<n;i++){
        	fputs(a[i],fp);
        	fputs("\n",fp);
    	}
    	fclose(fp);
    	scanf("%d",&n);
    }
    fa=fopen("text01.txt","r");
    while(fgets(b,300,fa)!=NULL)
    	printf("%s",b);
    return 0;
}
