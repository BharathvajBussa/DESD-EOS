#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int count;
pthread_rwlock_t rwlock;

void *calib(void *data)
{
    while(1)
    {   
        printf("calib asking for lock\n");
        pthread_rwlock_wrlock(&rwlock);
        printf("calib got lock\n");
        sleep(2);
        count++;
        printf("calib:%d\n",count);
        pthread_rwlock_unlock(&rwlock);
        printf("calib unlock\n");
    }
}

void *reading(void *data)
{
    while(1)
    {   sleep(10);
        printf("read asking for lock\n");
        pthread_rwlock_rdlock(&rwlock);
        printf("read got lock\n");
        printf("read:%d\n",count);
        pthread_rwlock_unlock(&rwlock);
        printf("read unlock\n");
    }
}
void *display(void *data)
{
    while(1)
    {
        printf("display asking for lock\n");
        pthread_rwlock_rdlock(&rwlock);
        printf("display got lock\n");
        sleep(5);
        printf("display:%d\n",count);
        pthread_rwlock_unlock(&rwlock);
        printf("display unlock\n");
    }
}

int main()
{
    pthread_t cid,rid,did;
    pthread_create(&cid,NULL,calib,NULL);
    pthread_create(&rid,NULL,reading,NULL);
    pthread_create(&did,NULL,display,NULL);
    pthread_join(cid,NULL);
    pthread_join(rid,NULL);
    pthread_join(did,NULL);
    pthread_rwlock_destroy(&rwlock);
    return 0;
}