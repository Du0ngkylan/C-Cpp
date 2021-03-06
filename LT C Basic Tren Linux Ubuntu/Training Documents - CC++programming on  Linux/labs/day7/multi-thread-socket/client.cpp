#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include "sock_defs.h"

int main(int argc, char* argv[]){
    int sock_fd;
    int res;
    sockaddr_in addr;
    socklen_t addr_len;
    char buf[250];
    
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1){
        perror("Can't creat a new client socket");
        exit(1);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(HOST_ADDR);
    addr.sin_port = htons(PORT);
    
    addr_len = sizeof(addr);
    
    res = connect(sock_fd, (sockaddr*)&addr, addr_len);
    if (res == -1){
        perror("Can't connect to server");
        exit(1);
    }
    memset(buf, 0, 250);
    printf("Type a text: ");
    fgets(buf, 250, stdin);
    res = write(sock_fd, buf, strlen(buf) + 1);
    if (res < 0){
        perror("Can't write data to server");
        exit(1);
    }
    memset(buf, 0, 250);
    res = read(sock_fd, buf, 250);
    if (res < 0){
        perror("Can't read data feedback from server");
        exit(1);
    }
    
    printf("Feedback data from server is: %s\n", buf);
    exit(0);
}
