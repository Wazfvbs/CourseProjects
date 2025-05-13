#include "stdio.h"
#include "unistd.h"
int main(){
	int x=5;

	if(fork()==0){
  		x=x+30;
		printf("ppid=%d pid=%d %d\n",getppid(),getpid(),x);
	}else
		printf("ppid=%d pid=%d %d\n",getppid(),getpid(),x);


	printf("ppid=%d pid=%d %d\n",getppid(),getpid(),x);
	
	while(1) sleep(1);
 }

