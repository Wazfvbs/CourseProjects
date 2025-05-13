#include "stdio.h"
#include "unistd.h"
int main(){
	pid_t pid1,pid2;
	pid1=fork();
	pid2=fork();
	printf("pid1=%d,pid2=%d\n",pid1,pid2);
	while(1)  sleep(1);
}