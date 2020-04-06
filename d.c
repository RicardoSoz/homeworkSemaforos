#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc, char *argv[]){
	struct sembuf operacion;
	int id=atoi(argv[0]), semaforo=atoi(argv[1]), respuesta=atoi(argv[2]), n = 3,value;
	
	operacion.sem_num = semaforo;
	operacion.sem_flg = 0;
	if(respuesta ==1){
	operacion.sem_op = n;
	} else if (respuesta ==2){
	operacion.sem_op = -n;
	}
	semop(id, &operacion, 1);
	value = semctl(id, semaforo, GETVAL, 0);
	printf("El valor del semaforo: %d \n", value);
	return 0;	

}
