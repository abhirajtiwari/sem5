//Server program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

int calc(int buff[3]) {
    switch ((char) buff[2]) {
        case '-':
            return buff[0] - buff[1];
        case '+':
            return buff[0] + buff[1];
        case '*':
            return buff[0] * buff[1];
        case '/':
            return buff[0] / buff[1];
    }
}

int main()
{
    int sd, nd, n, len;
    struct sockaddr_in seraddress, cliaddr;
    int buf[3];
    sd = socket(AF_INET, SOCK_STREAM, 0);
    seraddress.sin_family = AF_INET;
    seraddress.sin_addr.s_addr = INADDR_ANY;
    seraddress.sin_port = htons(10200);
    bind(sd, (struct sockaddr*)&seraddress, sizeof(seraddress));
    listen(sd, 5);
    len = sizeof(cliaddr);
    while (1)
    {
        nd = accept(sd, (struct sockaddr*)&cliaddr, &len);
        if (fork() == 0) {
            close(sd);
            n = read(nd, buf, sizeof(buf));
            int result = calc(buf);
            printf("%d\n", result);
            write(nd, &result, sizeof(result));
            close(nd);
            break;
        }
        close(nd);
    }
}