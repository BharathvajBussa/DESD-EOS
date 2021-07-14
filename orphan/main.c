#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;
    id=fork();
    if(0==id)
    {
        printf("Child Process\n");
        sleep(8);
        printf("Child Process ID: %d\n",getpid());
        printf("Child Process Parent ID: %d\n",getppid());
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent Process ID: %d\n",getpid());
        printf("Parent Process Parent ID: %d\n",getppid());  
    }
}