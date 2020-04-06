#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int i;
	pid_t pid;

		
	for(i = 0; i<4; i++){
		pid = fork();
		printf("PID: %d\n", pid);
	}

	return 0;
}
