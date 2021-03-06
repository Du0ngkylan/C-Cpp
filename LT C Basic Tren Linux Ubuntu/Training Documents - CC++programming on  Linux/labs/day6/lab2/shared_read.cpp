#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shared_defs.h"
#include <iostream>
using namespace std;

int main(){
	key_t key = ftok(KEY_FILE, ID);
	int shmid = shmget(key, SHARED_SIZE, 0);
	if (shmid == -1){
		perror("Can't get shared memory");
		return 1;
	}
	char* addr = (char*)shmat(shmid, 0, 0);
	if (addr == NULL){
		perror("Can't attach shared memory to process");
		return 1;
	}
	int* stop = (int*)addr;
	country *con = (country*)((char*)addr+sizeof(int));
	printf("Read Vietnam from shared memory\n");
	cout<< "pop: "<<con->pop<<endl;
	cout<<"name: "<<con->name<<endl;
	cout<<"cap: "<<con->cap<<endl;
	cout<<"cur: "<<con->cur<<endl;
	sleep(10);
	*stop = 0;
	sleep(1);
	printf("Read America from shared memory\n");
	cout<< "pop: "<<(con+1)->pop<<endl;
	cout<<"name: "<<(con+1)->name<<endl;
	cout<<"cap: "<<(con+1)->cap<<endl;
	cout<<"cur: "<<(con+1)->cur<<endl;
	*stop = 0;
	if (shmdt(addr) == -1){
		perror("Can't detach shared memory");
		return 1;
	}
	return 0;
}
