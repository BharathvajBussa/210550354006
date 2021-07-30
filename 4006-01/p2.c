#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t mymq;
struct mq_attr mymq_attr;
char buff[128];
int msg_prio;
int main()
{   int i;
    mymq_attr.mq_flags =0;
    mymq_attr.mq_maxmsg=5;
    mymq_attr.mq_msgsize=128;
    mymq_attr.mq_curmsgs= 0;
    mymq=mq_open("/mymq",O_RDONLY | O_CREAT,S_IRUSR | S_IWUSR,&mymq_attr);
    while(1)
    {
    mq_receive(mymq,buff,128,&msg_prio);
    i=0;
    while(buff[i]!='\0')
    {
        i++;
    }
    printf("length of %s is %d",buff,i);
    }
}