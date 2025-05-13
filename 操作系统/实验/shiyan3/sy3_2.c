#include "stdio.h"
#include "unistd.h"
#include "malloc.h"

int main(){
int * xp=(int *)malloc(sizeof(int));
*xp=5;

	if(fork()==0){
  		*xp=*xp+30;
	printf("ppid=%d pid=%d %d      xp=%u\n",getppid(),getpid(),*xp,xp);
	}else{
		sleep(3);
		printf("ppid=%d pid=%d %d  xp=%u\n",getppid(),getpid(),*xp,xp);
	}
//	while(1) sleep(1);
 }

