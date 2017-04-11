server:
	#c++ -o server server.cpp;
	gcc -lcrypto -lssl -o ssl_server ssl_server.cpp
client: 
	c++ -o client client.cpp
all:
	make server; make client;
