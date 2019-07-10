#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<signal.h>
#include<unistd.h>

static void signal_handler(int signum)
{
    printf("receive a signal from gloabalfifo , signalnum is:%d\n",signum);
}

int main(int argc ,char *argv[])
{
    int fd,oflags;
    fd = open("/dev/globalfifo",O_RDWR,S_IRUSR|S_IWUSR);
    if(fd != -1){
        signal(SIGIO,signal_handler);
        fcntl(fd,F_SETOWN,getpid());
        oflags = fcntl(fd,F_GETFL);
        fcntl(fd,F_SETFL,oflags|FASYNC);
        while (1)
        {
            sleep(1000);
        }
        
    }else{
        printf("device open failed\n");
        return -1;
    }

    return 0;
}