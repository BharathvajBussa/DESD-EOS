#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int count=0;
sem_t sem_count;
void *incThread(void *data)
{
    while(1)
    {
    sem_wait(&sem_count);
    count++;
    printf("Inc Count: %d\n",count);
    sem_post(&sem_count);
    }
}
void *decThread(void *data)
{   
    while (1)
    {
    sem_wait(&sem_count);
    count--;
    printf("Dec Count: %d\n",count);
    sem_post(&sem_count);
    }
}

int main()
{   
    pthread_t incID,decID; 
    sem_init(&sem_count,0,1);
    pthread_create(&incID,NULL,incThread,NULL);
    pthread_create(&decID,NULL,decThread,NULL);
    pthread_join(incID,NULL);
    pthread_join(decID,NULL);
    sem_destroy(&sem_count);
    return 0;
}