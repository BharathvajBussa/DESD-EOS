#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
 pid_t id;
 id=getpid();
 printf("\nProcess ID is : %d",id);
 id=getppid();
 printf("\nProcess Parent ID is : %d",id);
 return 0;
}
