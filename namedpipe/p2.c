#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    fd=open("myfifo",O_WRONLY);
    write(fd,"hello\n",6);
    close(fd);
    return 0;
}