#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main(void){
	pid_t pid;
	pid_t pid2;
	int i, j;

	fork();
	pid = getpid();
	pid2 = wait(&j);
	
	for(i=1; i<=10; i++){
		printf("Pid:: %d with value %d\n", pid, i);
	}
}
