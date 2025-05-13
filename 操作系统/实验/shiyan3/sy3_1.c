#include "stdio.h"
#include "unistd.h"
#include "malloc.h"

int main(){
	int x=5;

	if(fork()==0){
  		x=x+30;

	printf("ppid=%d pid=%d x= %d      xp=%u\n",getppid(),getpid(),x,&x);
	}else{
		sleep(3);

	printf("ppid=%d pid=%d x= %d      xp=%u\n",getppid(),getpid(),x,&x);
	}
	
//	while(1) sleep(1);
 }

