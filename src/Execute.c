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

int own_cmd_handler(char ** parsed) {

	int cl = 0;
	if (parsed[0] == NULL)return 0;
	if (parsed[0] != NULL && parsed[1] != NULL ) cl = 1 ;
	char * cmd = parsed[0];
	if (cl) {


		char* pipes[2];
		pipes[0] = cmd;
		pipes[1] = parsed[1];

		if (!strcmp(pipes[0], "color")) {
			if (!strcmp(pipes[1], "r"))RED();
			else if (!strcmp(pipes[1], "b"))BLUE();
			else if (!strcmp(pipes[1], "k"))BLACK();
			else if (!strcmp(pipes[1], "g"))GREEN();
			else if (!strcmp(pipes[1], "y"))YELLOW();
			else if (!strcmp(pipes[1], "c"))CYAN();
			else if (!strcmp(pipes[1], "m"))MAGNETA();
			else if (!strcmp(pipes[1], "a"))RESET_COLOR();
			else if (!strcmp(pipes[1], "help")) {
				RESET_COLOR();

				printf("####### COLOR YARDIM #######\n");
				RED();
				printf("# RED     = color r\n");
				BLACK();
				printf("# BLACK   = color k\n");
				BLUE();
				printf("# BLUE    = color b\n");
				GREEN();
				printf("# GREEN   = color g\n");
				YELLOW();
				printf("# YELLOW  = color y\n");
				CYAN();
				printf("# CYAN    = color c\n");
				MAGNETA();
				printf("# MAGNETA = color m\n");
				RESET_COLOR();
				printf("# RESET   = color a\n");
				printf("############################\n\n");
			} else {
				RESET_COLOR();
				return 0;
			}
			return 1;
		}
	}


	if (!strcmp(cmd , "clear"))clear();
	else if (!strcmp(cmd , "help"))help_open();
	else if (!strcmp(cmd , "exit"))m_exit();
	else if (!strcmp(cmd , "quit"))m_exit();
	else if (!strcmp(cmd, "showpid"))showpid();
	else if (!strcmp(cmd , "cd"))changeDirectory(parsed);
	else return 0;

	return 1;
}


// own commands

void clear() {
	printf("\033[H\033[J");
}


void m_exit() {
	printf("\nGüle Güle \n** Yine Bekleriz *\n* matrix iyi günler diler. **\n");
	exit(0);

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

//Kabuk tarafından oluşturulmuş en az 5 yavru proses PID’sini ekrana yazdırır
void showpid(){
	int iter = 0;
	for(iter; iter < array_size ; iter++)
	{
		printf("%lu\n", pid_array[iter]);
	}
}