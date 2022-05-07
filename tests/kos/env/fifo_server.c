#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BSIZE 1024*32
#define PORT_CLIENT 1490
#define SA struct sockaddr

const char * myfifo = "/tmp/myfifo";

int connect_client() {
    struct sockaddr_in servaddr, cli;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    } else {
        printf("Socket successfully created..\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT_CLIENT);

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    } else {
        printf("connected to the server..\n");
    }

    return sockfd;
}

int write_fifo(char *str1, int size) {
    int fd1 = open(myfifo,O_WRONLY);
    int ret = write(fd1, str1, size);
    close(fd1);
    return ret;
}

int read_fifo(char *str1) {
    int fd1 = open(myfifo, O_RDONLY);
    int ret = read(fd1, str1, BSIZE);
    close(fd1);
    return ret;
}

int main() {
    int fd1;
    mkfifo(myfifo, 0666);
    int main_sock = -1;

    while (1) {
        char str1[BSIZE] = {0};

        int ret = read_fifo(str1);
        printf("Read from FIFO %d bytes\n", ret);

        if (0 > main_sock) {
            main_sock = connect_client();
        }

        ret = write(main_sock, str1, ret);
        printf("Write to SAMBA %d bytes\n", ret);

        memset(str1, 0, BSIZE);
        ret = read(main_sock, str1, BSIZE);
        printf("Read from SAMBA %d bytes\n", ret);
        if (0 >= ret) {
            perror("Disconnect");
            close(main_sock);
            main_sock = -1;
            write_fifo("kosdone", strlen("kosdone"));
            continue;
        }

        ret = write_fifo(str1, ret);
        printf("Write to FIFO %d bytes\n", ret);
    }

    return 0;
}