#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	switch(fork()){
		case 0:
			printf("Codigo del hijo %d\n", getpid());
			break;
		default:
			printf("Codigo del padre: %d\n", getpid());
			break;
		case -1:
			printf("Error");
		}
	return(EXIT_SUCCESS);
}
