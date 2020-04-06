#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
	printf("Mi PID: %d\n", getpid());
	printf("Mi PPID: %d\n", getppid());
	return(EXIT_SUCCESS);
}
