# Riley Taylor
# makefile for assignment 3 client/server
# make all will make the client and server
# make client will make the client
# make server will make the server
# make clean will remove .o files as well as 
# server and clients if available
# make cpplint will run cpplint on client or server
# make run will run client or server, note server on port 7777
all: client server

client: client.o
	g++ -c PracticalSocket.cpp
	g++ -Wall -o client clientapp.cpp client.o PracticalSocket.o
client.o: client.cpp client.h
	g++ -Wall -c client.cpp

server: server.o
	g++ -c PracticalSocket.cpp
	g++ -Wall -o server serverapp.cpp server.o PracticalSocket.o
server.o: server.cpp server.h
	g++ -Wall -c server.cpp

clean:
	rm *.o client server

cpplint-client:
	cpplint --filter=-build/include_subdir client.h client.cpp clientapp.cpp

cpplint-server:
	cpplint --filter=-build/include_subdir server.h server.cpp serverapp.cpp

run-client:
	./client localhost 7777

run-server:
	./server 7777