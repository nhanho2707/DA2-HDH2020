//Run by command: gcc pthread bai1 and then run a.out file



#include "stdio.h"
#include "semaphore.h"
#include "pthread.h"
#include "signal.h"
#include <stdlib.h>
#include <unistd.h>

pthread_t ThreadA;
pthread_t ThreadB;

sem_t Semaphore_1;
sem_t Semaphore_2;

int isLoop=1;
int X=0;

void *FunctionA(void *data)
{
    while (1)
    {
        X++;
        printf("%d\n",X);
        if (X==20)
        {
            X=0;
        }
    }
    
}


void *FunctionB(void *data)
{
    while (1)
    {
        sleep(1);
        X++;
        printf("%d\n",X);
        if (X==20)
        {
            X=0;
        }
        
    }
    
}
int main()
{
    sem_init(&Semaphore_1,1,0);
    sem_init(&Semaphore_2,1,10);
    pthread_create(&ThreadB,NULL,&FunctionB,NULL);
    pthread_create(&ThreadA,NULL,&FunctionA,NULL);
    while (isLoop)
    {
    
    }
    return 0;

}
