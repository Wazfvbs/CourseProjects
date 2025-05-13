#include "stdio.h"
#include "unistd.h"
#include "unistd.h"
int main(){
	fork();
	if(fork()==0){  
		fork();		
		printf("ppid=%d pid=%d \n",getppid(),getpid());
		while(1)  sleep(1);
	}else{
		printf("ppid=%d pid=%d \n",getppid(),getpid());
		while(1)  sleep(1);
	}
 }
