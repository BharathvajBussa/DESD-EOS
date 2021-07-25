#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t mymq;
struct mq_attr mymq_attr;

int main()
{
    mymq_attr.mq_flags =0;
    mymq_attr.mq_maxmsg= 4;
    mymq_attr.mq_msgsize= 128;
    mymq_attr.mq_curmsgs= 0;

    mymq= mq_open("/mymq",O_WRONLY | O_CREAT,S_IRUSR | S_IWUSR,&mymq_attr);

    mq_send(mymq,"Hello\n",6,0);

    mq_close(mymq);
    return 0;
}