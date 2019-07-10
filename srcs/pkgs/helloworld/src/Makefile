# build helloworld executable when user executes "make"  
CFLAGS += -g -Wall -D_GNU_SOURCE
#LDLIBS += -lubox -lubus -ljson-c -lblobmsg_json -ldl
LDLIBS += -lubox -lubus -ljson-c -ldl
all: helloworld ubus_hello
  
helloworld: helloworld.o  
	$(CC) $(LDFLAGS) helloworld.o -o helloworld  
        
helloworld.o: helloworld.c  
	$(CC) $(CFLAGS) -c helloworld.c  
 
ubus_hello: ubus_hello.o
	$(CC) $(CFLAGS) $(LDLIBS) $(LDFLAGS)-o $@ $^
	              
# remove object files and executable when user executes "make clean"  
clean:  
	rm *.o helloworld  
