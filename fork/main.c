#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t ret;
    ret=fork();
    if(0==ret)
    {
        printf("Child PID is: %d\n",getpid());
        printf("Child PPID is: %d\n",getppid());
    }
    else
    {
        printf("Parent PID is: %d\n",getpid());
        printf("Parent PPID is: %d\n",getppid());
    }
    return 0;
}