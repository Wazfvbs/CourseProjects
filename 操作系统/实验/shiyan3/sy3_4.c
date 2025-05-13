#include "stdio.h"
#include "unistd.h"
#include "malloc.h"
#include "sys/mman.h"

int main(){
int * xp=(int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_ANON|MAP_SHARED,-1,0);
*xp=5;

	if(fork()==0){
  		*xp=*xp+30;

		printf("ppid=%d pid=%d %d  xp=%d\n",getppid(),getpid(),*xp,xp);
	}else{
//		sleep(3);
		printf("ppid=%d pid=%d %d  xp=%d\n",getppid(),getpid(),*xp,xp);
	}
sleep(3);
munmap(xp,sizeof(int));	
//	while(1) sleep(1);
 }

