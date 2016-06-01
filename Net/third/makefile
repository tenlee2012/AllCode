#makefile
SERVOBJ=sockutil.o server.o socklink.o
CLITOBJ=sockutil.o client.o
CFLAGS=-lpthread

server:${SERVOBJ}
	gcc  -o $@ ${SERVOBJ} ${CFLAGS}
client:${CLITOBJ}
	gcc  -o $@ ${CLITOBJ} ${CFLAGS}
clean:
	rm -rf ${CLITOBJ} ${SERVOBJ} 
