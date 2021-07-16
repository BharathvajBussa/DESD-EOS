#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 64
int main()
{
    pid_t id;
    int pfd[2];
    int pfd1[2];
    unsigned char buff[SIZE];
    unsigned char buff1[SIZE];
    pipe(pfd);
    pipe(pfd1);
    id=fork();

    if(0==id)
    {
        printf("Child process\n");
        close(pfd1[1]);
        read(pfd1[0],buff,SIZE);
        printf("Message from parent:%s\n",buff);
        close(pfd1[0]);
        //reply
        close(pfd[0]);
        write(pfd[1],"OK\n",3);
        close(pfd[1]);
    }
    else
    {
        printf("Parent Process\n");
        close(pfd1[0]);
        write(pfd1[1],"hello",5);
        close(pfd1[1]);
        //response
        close(pfd[1]);
        read(pfd[0],buff1,SIZE);
        printf("Reply:%s\n",buff1);
        close(pfd[0]);
    }
    return 0;
}