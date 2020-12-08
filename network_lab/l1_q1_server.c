#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include <string.h>
#define PORT 5000
#define MAXLINE 1000
// Server code
int main()
{
	int matrix[10][10];
	int buffer[100];
	char buff[100];
	int servsockfd, len, n;
	struct sockaddr_in servaddr, cliaddr;
	bzero(&servaddr, sizeof(servaddr));
// Create a UDP Socket
	servsockfd = socket(AF_INET, SOCK_DGRAM, 0);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;
// bind server address to socket descriptor
	bind(servsockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
//receive the datagram
	len = sizeof(cliaddr); 
	for (int i = 0; i < 10; ++i) {
		n = recvfrom(servsockfd, buffer, 10*sizeof(int), 0, (struct sockaddr*)&cliaddr, &len);
		for (int j = 0; j < 10; ++j) matrix[i][j] = buffer[j];
	}
//Echoing back to the client
	strcpy(buff,"matrix recieved\0");
	sendto(servsockfd, buff, sizeof(buff), 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr));
	for (int i = 0; i < 10; ++i) {
		for ( int j = 0; j < 10; ++j) printf("%d\t", matrix[i][j]);
		printf("\n");
	}
// close the descriptor
	close(servsockfd);
}