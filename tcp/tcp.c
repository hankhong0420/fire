#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define HOST "127.0.0.1"
#define PORT 6666
#define BUFFER_SIZE (4 * 1024)

int main()
{
	int sockfd, ret;
	struct sockaddr_in server;
	char buffer[BUFFER_SIZE];
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		printf("create an endpoint for communication fail\n");
		exit(-1);
	}
	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr(HOST);
	
	if(connect(sockfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1){
	printf("connect server success\n");
	close(sockfd);
	exit(1);



}
printf("connect server sucess\n");
while(1) {
	printf("please enter some test:");
	fgets(buffer, BUFFER_SIZE, stdin);
	if(strncmp(buffer, "end", 4) == 0)
		break;
	write(sockfd, buffer, sizeof(buffer));
	
}
	close(sockfd);
	exit(0);



}
