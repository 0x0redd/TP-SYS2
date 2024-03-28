#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char * argv[]) {

	pid_t pid1,pid2,pid_premier;
	int processus;
	switch(pid1=fork()) {
	case -1:
		printf("erreur\n");
		break;
	case 0:
		execlp("ls","ls","-al",NULL);
		break;
	default:
		switch(pid2=fork()) {
		case -1:
			printf("erreur\n");
			break;
		case 0:
			execlp("ps","ps","-l",NULL);
			break;
		default:
			break;
	}
		break;
	}
	
	pid_premier = wait(&processus);
	wait(&processus);
	
	printf("\nLe premier processus a finir est : %d\n", (pid_premier==pid1)?1:2);
	return 0;
}
