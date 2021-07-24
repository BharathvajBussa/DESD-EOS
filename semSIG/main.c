#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int a,b,sum;
sem_t s1,s2;
void *input_thread(void *data)
{
    while(1)
    {
        sem_wait(&s1);
        printf("enter two digits: ");
        scanf("%d%d",&a,&b);
        sem_post(&s2);
    }
}
void *proc_thread(void *data)
{
    while(1)
    {
        sem_wait(&s2);
        sum=a+b;
        printf("sum= %d\n",sum);
        sem_post(&s1);
    }
}
int main()
{
    pthread_t inputID,procID;
    sem_init(&s1,0,1);
    sem_init(&s2,0,0);
    pthread_create(&inputID,NULL,input_thread,NULL);
    pthread_create(&procID,NULL,proc_thread,NULL);
    pthread_join(inputID,NULL);
    pthread_join(procID,NULL);
    sem_destroy(&s1);
    sem_destroy(&s2);
    return 0;
}