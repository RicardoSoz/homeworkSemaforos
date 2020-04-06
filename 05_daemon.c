#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	pid_t pid, sid;

	pid = fork();

	if(pid < 0){
		exit(EXIT_FAILURE);
	}
	if(pid > 0){
		exit(EXIT_SUCCESS);
	}
	umask(0);

	openlog(argv[0], LOG_NOWAIT | LOG_PID, LOG_USER);

	syslog(LOG_NOTICE, "Daemon inicio chido\n");

	sid = setsid();

	if(sid<0){
		syslog(LOG_ERR, "No se puede crear el session id\n");
		exit(EXIT_FAILURE);
	}

	if((chdir("/")) < 0 ){
		syslog(LOG_ERR, "No se puede cambiar directorio /\n");
		exit(EXIT_FAILURE);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	while(1){
		syslog(LOG_INFO, "Soy el dameon y estoy alive \n");
		sleep(15);
	}

	closelog();
}
