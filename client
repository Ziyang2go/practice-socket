#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>
#define DATA "This is my message!" 

int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in server;
	struct hostent *hp;
	sock = socket (AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("socket failed");
		exit(1);
	}
	server.sin_family = AF_INET;
	hp = gethostbyname(argv[1]);
	if(hp == 0)
	{
		perror("gethostname failed");
		close(sock);
		exit(1);
	}
	memcpy(&server.sin_addr,hp->h_addr,hp->h_length);
	server.sin_port = htons(5000);
	if(connect(sock,(struct sockaddr*) &server, sizeof(server)) <0)
	{
		perror("connetion failed");
		exit(1);
	}
	if(send(sock,DATA, sizeof(DATA),0) < 0) 
	{
		perror("Send failed");
		close(sock);
		exit(1);
	}
	else
	{
		printf("Sent %s\n",DATA);
		while(1)
		{}
		close(sock);
	}
	return 0;
}
