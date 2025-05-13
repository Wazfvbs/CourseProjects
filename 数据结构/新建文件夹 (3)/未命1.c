#include<stdio.h>

const int MAXN = 499;

long long int C[500][500];

void Initial()

{

 int i,j;

 for(i=0; i<=MAXN; ++i)

 {

  C[0][i] = 0;

  C[i][0] = 1;

 }

 for(i=1; i<=MAXN; ++i)

 {

  for(j=1; j<=MAXN; ++j)

  C[i][j] = (C[i-1][j] + C[i-1][j-1]);

 }

}

int main(){

int a=0,b;
Initial();
scanf("%d",&b);
while(b!=-1){
a++;
printf("%d %d %d",a,b,2*C[2*b][b]/(b+1));
scanf("%d",&b);
}

return 0;

}
