#include "stdio.h"
#include "unistd.h"
int main(void)
{
    int i;   
    for (i = 0; i < 3; i++) {
        if（fork()==0）break;
    }
   while(1)  sleep(1);	
}