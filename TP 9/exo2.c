#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    int i, j;
    int pid;
    FILE *fichier;
    int attente;

	printf("PID du processus Père : %d\n", getpid());

	printf("affichage des 6 premiers nombres : \n");

	fichier = fopen("nbpremier", "r");

	if (fichier == NULL){
		printf("Fichier introuvable\n");
		exit(-2);
	}
	for (j = 0; j < 6; j++){
		fscanf(fichier, "%d", &i);
		printf("%d\n", i);
	}

	printf("Creation du fils\n");
	pid = 0;
	pid = fork();

	if(pid == -1){
		printf("impossible de creer un fils\n");
		exit(-1);
	} else if (pid == 0){
		printf("PID du processus fils: %d\n", getpid());
 		printf("Affichage des 10  nombres suivante\n");
 		for (j = 0; j < 10; j++){
     			fscanf(fichier, "%d", &i);
     			printf("%d\n", i);	
		}
 		fclose(fichier);
 		printf("le fils est mort\n");
 		exit(1);
    	} else {
		printf("Pere attent la mort du Fils\n");
 		wait(&attente);
 		printf("Le pere continue la lecture\n");
		while (!feof(fichier)) {
     			fscanf(fichier, "%d", &i);
    			printf("%d\n", i);
 		}

 		fclose(fichier);
	}
    	printf("Le pere se termine\n");
    	return 0;
}
