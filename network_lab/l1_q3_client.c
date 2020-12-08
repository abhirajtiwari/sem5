//TCP Client program:
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
int main()
{
    int sd, nd, n, len, reult, n1;
    struct sockaddr_in seraddress, cliaddr;
    int buf1;

    int nums[3];
    printf("Enter First number\n");
    scanf("%d", &nums[0]);
    printf("Enter Second number\n");
    scanf("%d", &nums[1]);
    printf("Enter operator\n");
    while ((getchar()) != '\n'); 
    char op = getchar();
    nums[2] = (int)op;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    seraddress.sin_family = AF_INET;
    seraddress.sin_addr.s_addr = INADDR_ANY;
    seraddress.sin_port = htons(10200);
    len = sizeof(seraddress);
    connect(sd, (struct sockaddr*)&seraddress, len);
    // printf("enter the message tosen \n");
    // gets(buf);
    n = write(sd, nums, sizeof(nums));
    n1 = read(sd, &buf1, sizeof(buf1));
    printf("message from ser %d\n", buf1);
    getchar();
}
