#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

void clifunc(int sock) {
    char ch='a';
    write(sock, &ch, sizeof(ch));
    int ret;
    read(sock, &ret, sizeof(int));
    printf("Server returned %d\n", ret);
}

void main() {
    //172.16.48.95:7777
    int sock;
    struct sockaddr_in server_address, client_address;
    server_address.sin_addr.s_addr = inet_addr("172.16.48.95");
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(7777);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(sock, &server_address, sizeof(server_address)) != 0) {
        printf("Couldn't connect to server.\n");
        exit(0);
    }
    clifunc(sock);
} 