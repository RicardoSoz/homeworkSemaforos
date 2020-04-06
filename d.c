#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define NSEM 1

int main(int argc, char *argv[]){

	int value, sem, semid, numsem, opcion, n;
	int id =atoi(argv[1]);
	opcion=atoi(argv[2]); 
	n = 1;
	
	semid = semget(id, NSEM, IPC_CREAT | 0600);
	numsem = 0;
	struct sembuf operacion;
	
	operacion.sem_num = numsem;
	operacion.sem_flg = 0;

	if(opcion == 1){
		operacion.sem_op = n;
	}
	else if(opcion == 2){
		operacion.sem_op = -n;
	}else {
		printf("Error option \n");
		exit(-1);
	}

	value=semop(semid, &operacion, 1);
	if (value==-1){
		printf("Error %d \n", value);
		exit(-1);
	}else{
		sem = semctl(semid, numsem, GETVAL, 0);
		printf("El valor del semaforo: %d \n", sem);
	}

}
