#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>

int main()
{
    int fd;
    mkfifo("myfifo",S_IRUSR | S_IWUSR);
    fd=open("myfifo",O_WRONLY);
    write(fd,"hello\n",6);
    close(fd);
    return 0;
}