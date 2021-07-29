#include <stdio.h>
#include <pthread.h>

int event=0;
pthread_mutex_t eventMutex;
pthread_cond_t eventCV;

void *checkevent(void *data)
{   
    printf("CE:Grabbing Mutex\n");
    pthread_mutex_lock(&eventMutex);
    printf("CE:checking event\n");
    while(event!=1)
    {
        pthread_cond_wait(&eventCV,&eventMutex);
    }
    printf("CE:event is SET\n");
    pthread_mutex_unlock(&eventMutex);
    printf("CE:Mutex unlock\n");    
}
void *setevent(void *data)
{
    printf("SE:Grabbing Mutex\n");
    pthread_mutex_lock(&eventMutex);
    printf("SE:setting event\n");
    event=1;
    pthread_mutex_unlock(&eventMutex);
    printf("SE:Mutex unlock\n");
    pthread_cond_signal(&eventCV);
    printf("SE:signalling\n");
}

int main()
{
    pthread_t cid,sid;
    pthread_cond_init(&eventCV, NULL);
    pthread_create(&cid,NULL,checkevent,NULL);
    pthread_create(&sid,NULL,setevent,NULL);
    pthread_join(cid,NULL);
    pthread_join(sid,NULL);
    return 0;
}
