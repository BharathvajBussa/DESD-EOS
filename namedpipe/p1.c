#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

#define SIZE 64
int main()
{   
    int fd;
    unsigned char buff[SIZE];
    fd=open("myfifo",O_RDONLY);
    read(fd,buff,SIZE);
    printf("Message received from P2:%s",buff);
    return 0;
}