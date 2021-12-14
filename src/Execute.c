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

void exec_cmd_piped3(char **parsed, char * parsedpipe[MAXLINE][MAXLINE]) {

	for (int i = 0; i < MAXLINE; ++i)
	{
		if (parsedpipe[i] == NULL || parsedpipe[i][0] == NULL )break;
		if (own_cmd_handler(parsedpipe[i])) continue;
		exec_cmd(parsedpipe[i]);
	}
}

void help_open() {
	puts("\n**MATRIX Yardim **"
	     "\nCopyright @ Ayse Aysima Savas, Yusuf Sonmez, Melek Selin Uysal, Seyma Gol, Ruhid Ibadli"
	     "\n-matrix i kullanırkan oluşabilecek butun hasarlardan siz sorumlusunuz."
	     "\nDesteklenen Ekstra kodlar:"
	     "\n>cd"
	     "\n>showpid"
	     "\n>exit"
	     "\n>UNIX shell de bulabileceginiz butun temel komutlara sahiptir"
	     "\n>Sirali komut calistirabilir");
	return;
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