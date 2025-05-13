#include "stdio.h"
#include "unistd.h"
#include "malloc.h"
#include "sys/mman.h"
#include "semaphore.h"
int main(){
int * xp=(int *)mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_ANON|MAP_SHARED,-1,0);
*xp=5;
sem_t * sem1= (sem_t * )mmap(NULL, sizeof(sem_t), PROT_READ|PROT_WRITE, MAP_ANON|MAP_SHARED, -1, 0);
sem_init(sem1,1,0);

	if(fork()==0){
  		*xp=*xp+30;
		sem_post(sem1);
		printf("ppid=%d pid=%d %d  xp=%u\n",getppid(),getpid(),*xp,xp);
	}else{
		sem_wait(sem1);  	//sleep(3);
		printf("ppid=%d pid=%d %d  xp=%u\n",getppid(),getpid(),*xp,xp);
	}
sleep(3);
munmap(xp,sizeof(int));

munmap(sem1,sizeof(sem_t));
//	while(1) sleep(1);
 }

