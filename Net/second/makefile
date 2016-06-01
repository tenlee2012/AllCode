SERVEROBJ=msg.o server.o sockutil.o
CLIENTOBJ=client.o sockutil.o

server:${SERVEROBJ}
	gcc ${SERVEROBJ} -o server

client:${CLIENTOBJ}
	gcc ${CLIENTOBJ} -o client

clean:
	rm -rf ${SERVEROBJ} server client

