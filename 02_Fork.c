#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void main(void){
	pid_t pid;
	int i;

	fork();
	pid = getpid();
	for(i = 1; i <=200; i++){
		printf("Esta linea se orogino en PID %d con valor %d\n", pid, i);
	}
}
