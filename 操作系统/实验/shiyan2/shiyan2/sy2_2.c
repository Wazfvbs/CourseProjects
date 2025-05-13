#include "stdio.h"
#include "unistd.h"
int main(){	
	if(fork()==0){  		
		printf("ppid=%d pid=%d \n",getppid(),getpid());
		while(1)  sleep(1);
	}else{
		printf("ppid=%d pid=%d \n",getppid(),getpid());
		while(1)  sleep(1);
	}
 }