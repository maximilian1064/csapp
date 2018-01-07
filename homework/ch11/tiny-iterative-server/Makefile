CC = gcc

all: client server

client: client.o
	$(CC) -pthread $< ../../csapp.o -o $@

server: server.o
	$(CC) -pthread $< ../../csapp.o -o $@

%.o: %.c
	$(CC) -c -pthread -I../../ $< -o $@ 

clean:
	rm *.o client server
