#include "stdio.h"
#include "unistd.h"
#include "malloc.h"
#include "sys/mman.h"
#include "semaphore.h"
int  x=5;
sem_t m1;
void * f1(void * t){
	x=x+30;
	 sem_post(&m1);
	printf("ppid=%d pid=%d x= %d      xp=%u\n",getppid(),getpid(),x,&x);
}
void * f2(void * t){
	sem_wait(&m1);
	//sleep(3);
	printf("ppid=%d pid=%d x= %d      xp=%u\n",getppid(),getpid(),x,&x);
}

int main(){
        pthread_t th1,th2;
        sem_init(&m1,0,0);
       
        pthread_create(&th1,NULL,f1,NULL);
        pthread_create(&th2,NULL,f2,NULL);

        pthread_join(th1,NULL);
        pthread_join(th2,NULL);
 }

