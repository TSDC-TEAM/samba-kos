#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX 1024*32
#define PORT_SERVER 445
#define SA struct sockaddr

const char * myfifo = "/tmp/myfifo";

int write_fifo(char *buff, int size) {
    int fd1 = open(myfifo, O_WRONLY);
    int ret = write(fd1, buff, size);
    close(fd1);
    return ret;
}

int read_fifo(char *buff, int size) {
    int fd1 = open(myfifo, O_RDONLY);
    int ret = read(fd1, buff, size);
    close(fd1);
    return ret;
}

void func(int connfd) {
    mkfifo(myfifo, 0666);

    char buff[MAX];
    for (;;) {
        bzero(buff, MAX);

        int ret = read(connfd, buff, sizeof(buff));
        printf("Read from ENV %d bytes\n", ret);
        if (0 >= ret) {
            perror("Disconnect");
            break;
        }

        ret = write_fifo(buff, ret);
        printf("Write to FIFO %d bytes\n", ret);

        bzero(buff, MAX);
        ret = read_fifo(buff, MAX);
        printf("Read from FIFO %d bytes\n", ret);

        if (strncmp("kosdone", buff, strlen("kosdone")) == 0) {
            printf("FIFO closed\n");
            break;
        }

        ret = write(connfd, buff, ret);
        printf("Write to ENV %d bytes\n", ret);
    }
}

int main() {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    } else {
        printf("Socket successfully created..\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("10.53.57.3");
    servaddr.sin_port = htons(PORT_SERVER);

    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        perror("Why?");
        exit(0);
    } else {
        printf("Socket successfully binded..\n");
    }

    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    } else {
        printf("Server listening..\n");
    }
    len = sizeof(cli);

    while (1) {
        connfd = accept(sockfd, (SA*)&cli, &len);
        if (connfd < 0) {
            printf("server accept failed...\n");
            exit(0);
        } else {
            printf("server accept the client...\n");
        }
        func(connfd);
        close(connfd);
    }

    return 0;
}