#include <stdio.h>
int main
{
	printf("pid=%d\n",getpid());
	printf("ppid=%d\n",getppid());
	while(1)  sleep(1);
}