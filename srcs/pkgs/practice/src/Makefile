# build helloworld executable when user executes "make"  
CFLAGS += -g -Wall -D_GNU_SOURCE
#LDLIBS += -lubox -lubus -ljson-c -ldl
LDLIBS +=
all: globalfifo_poll globalfifo_epoll globalfifo_fasync globalfifo_aio
  
globalfifo_poll: globalfifo_poll.o  
	$(CC) $(LDFLAGS) globalfifo_poll.o -o globalfifo_poll  
        
globalfifo_poll.o: globalfifo_poll.c  
	$(CC) $(CFLAGS) -c globalfifo_poll.c  
 
globalfifo_epoll: globalfifo_epoll.o
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS)-o $@ $^

globalfifo_fasync: globalfifo_fasync.o
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS)-o $@ $^

globalfifo_aio: globalfifo_aio.o
	$(CC) $(CFLAGS) $(LDLIBS) -laio $(LDFLAGS)-o $@ $^
	              
# remove object files and executable when user executes "make clean"  
clean:  
	rm *.o globalfifo_epoll globalfifo_poll lobalfifo_fasync globalfifo_aio
