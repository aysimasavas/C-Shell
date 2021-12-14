#include "Execute.h"

int exec_cmd(char ** parsed) {

	if (own_cmd_handler(parsed)) return;

	// yeni bir cocuk proses forklama
	pid_t pid = fork();

	if (pid == -1) {
		// fork basarisiz olursa
		printf("\nSistem hatasi tekrar deneyiniz (Child Fork Error)..\n");
		return;
	} else if (pid == 0) {
		if (execvp(parsed[0], parsed) < 0) {
			printf("Komut yok yada calistirilamiyor..\n");
		}
		exit(0);// cikma komutu
	} else {
		//cocuk prosessin sonlanmasını bekliyoruz
		int wait_res = waitpid(pid, NULL, 0);
		return wait_res;
	}
}

void changeDirectory(char* args[]) {
	if (args[1] == NULL) {
		chdir(getenv("HOME")); 
		return 1;
	}
	// Else we change the directory to the one specified by the 
	// argument, if possible
	else{ 
		if (chdir(args[1]) == -1) {
			printf(" %s: no such directory\n", args[1]);
            
		}
	}
	
}