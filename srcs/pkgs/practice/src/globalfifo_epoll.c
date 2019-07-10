#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/epoll.h>

#define FIFO_CLEAR 0x1
#define BUFFER_LEN 20


int main(int argc ,char *argv[])
{
    int fd;

    fd = open("/dev/globalfifo",O_RDONLY|O_NONBLOCK);
    if(fd != -1){
        struct epoll_event ev_globalfifo;
        int err;
        int epfd;

        if(ioctl(fd,FIFO_CLEAR,0) < 0){
            printf("ioctl command failed\n");
        }

        epfd = epoll_create(1);
        if(epfd < 0 ){
            perror("epoll_ereate failed\n");
            return -1;
        }

        bzero(&ev_globalfifo,sizeof(struct epoll_event));
        ev_globalfifo.events = EPOLLIN| EPOLLPRI;
        err = epoll_ctl(epfd,EPOLL_CTL_ADD,fd,&ev_globalfifo);
        if(err < 0){
            perror("epoll_crl");
            return -1;
        }
        err = epoll_wait(epfd,&ev_globalfifo,1,15000);
        if(err < 0){
            perror("epoll_wait");
        }else if(err == 0){
            printf("No data input in FIFO within 15 seconds\n");
        }else{
            printf("FIFO is not empty\n");
        }
        err = epoll_ctl(epfd,EPOLL_CTL_DEL,fd,&ev_globalfifo);
        if(err < 0 ){
            perror("epoll_ctl del");
            return -1;
        }
    }else{
        printf("Open device failed\n");
        return -1;
    }

    return 0;
}