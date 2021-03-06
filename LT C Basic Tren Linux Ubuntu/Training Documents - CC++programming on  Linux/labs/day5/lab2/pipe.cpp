#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
using namespace std;

int main(){
	int p2c[2]; // pipe: parent to child
	int c2p[2]; // pipe: child to parent
	
	if (pipe(p2c) == -1){
		 perror("Can't create pipe from parent to child");
		 return 1;
	}
	if (pipe(c2p) == -1){
		 perror("Can't create pipe from child to parent");
		 return 1;
	}
	pid_t pid = fork();
	if (pid == -1){
		perror("Can't create child process");
		return 1;
	} else if (pid == 0){
		close(p2c[1]);
		close(c2p[0]);
		char buf[250];
		while(1){
			memset(buf, 0, 250);
			if (read(p2c[0], buf, 250) <= 0){
				perror("Can't read data from parent");
				break;
			}
			for (int i = 0; i < strlen(buf); i ++){
				buf[i] = toupper(buf[i]);
			}
			if (write(c2p[1], buf, strlen(buf)+1) <= 0){
				perror("Can't write data to parent");
				break;
			}
		}
		close(p2c[0]);
		close(c2p[1]);
		exit(1);
	}
	
	close(p2c[0]);
	close(c2p[1]);
	char buf[250];
	while(1){
		memset(buf, 0, 250);
		if (fgets(buf, 250, stdin) <= 0){
			perror("Can't read data from keyboard");
			break;
		}
		if (write(p2c[1], buf, strlen(buf)+1) <= 0){
			perror("Can't write data to child");
			break;
		}
		memset(buf, 0, 250);
		if (read(c2p[0], buf, 250) <= 0){
			perror("Can't read data from child");
			break;
		}
		puts(buf);
	}
	close(p2c[1]);
	close(c2p[0]);
	return 1;
}
