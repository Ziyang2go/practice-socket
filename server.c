#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>

int main(int argc,char *argv[])
{

	int sock;
	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;
	int ret;
	if ( sock = socket(AF_INET,SOCK_STREAM,0) < 0) {
		perror("Failed to create socket");
		exit(1);
	}
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5000);
	if (bind(sock, (struct sockaddr*) &server, sizeof(server))) {
		perror("Bind failed");
		exit(1);
	}
	listen(sock,5);
	int fd = 0;
	while(1)
	{
		mysock = accept(sock, (struct sockaddr*) 0, 0);
		if(mysock == -1)
		{	perror("accept failed");
			exit(1);
		}
		memset(buff,0,1024);
		if((rval = recv(mysock,buff,sizeof(buff),0)) < 0) 
		{
			perror("reading stream msg error ");
		}
		if (rval == 0) 
		{
			printf("no input");
		}
		printf("GOt this message (rval = %d )\n", rval);
	}
	return 0;
}
