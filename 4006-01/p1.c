#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <mqueue.h>

mqd_t mymq;
struct mq_attr mymq_attr;
int main()
{
    int fd;
    char buff[128];
    mymq_attr.mq_flags =0;
    mymq_attr.mq_maxmsg =5;
    mymq_attr.mq_msgsize=128;
    mymq_attr.mq_curmsgs=0;

    fd=open("/usr/share/dictionary",O_RDONLY,S_IRUSR);

    mymq =mq_open("/mymq",O_WRONLY |O_CREAT,S_IRUSR |S_IWUSR,&mymq_attr);
    mq_send(mymq,buff,128,0);//buff is data from the file opened
    mq_close(mymq);
    return 0;
}