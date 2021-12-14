#include <signal.h>
#include "Parsing.h"
#include "Execute.h"

// Process id leri dizinin sonuna ekleyerek showpid fonksiyonuna
// destek olur.
void append(long newPid) {
	array_size += 1;

	long* temp_pid_array = malloc(array_size * sizeof(long));

	int iter = 0;
	for(iter; iter < array_size ; iter++)
	{
		if(iter + 1 == array_size ) 
			temp_pid_array[iter] = newPid;
		else
			temp_pid_array[iter] = pid_array[iter];
	}

	pid_array = temp_pid_array;
}

// Cizgileri terminale basar
void draw_line(int n, char * s) {
	for (int i = 0; i < n; ++i)
	{
		printf(s);
	}

}
void init() {

	clear();
	RED();
	draw_line(30, "*");
	printf("\n");
	RESET_COLOR();
	printf("#");
	draw_line(28, " ");
	printf("#");
	printf("\n");
	printf("#");
	draw_line(28, " ");
	printf("#");
	printf("\n");
	printf("#");
	draw_line(3, " ");
	printf("sau e hoşgeldiniz");
	draw_line(5, " ");
	printf("#");
	printf("\n");
	RESET_COLOR();
	printf("#");
	draw_line(28, " ");
	printf("#");
	printf("\n");
	printf("#");
	draw_line(28, " ");
	printf("#");
	printf("\n");
	BLUE();
	draw_line(30, "*");
	printf("\n");
	RESET_COLOR();
}

int  main(int argc, char const *argv[])
{

//interaktif mode

	char  str[MAXCHAR] ;
	char *parsedArgs[MAXLINE];
	char *parsedPipedArgs[MAXLINE];
	char *parsedPipedArgs3[MAXLINE][MAXLINE];
	int e_flag = 0;
	init();




	while (1) {

		// komut alma
        char cwd[150];
        if(getcwd(cwd, sizeof(cwd)) != NULL)
            printf("%s: ", cwd);
        
		printf("sau > ");
		char * fgts = fgets(str, MAXCHAR, stdin);
		if (fgts == NULL)m_exit();
		strtok(str, "\n");
		if (fgts[strlen(fgts) - 1] == '\n')continue;

		//komut kontrolu
		if (strlen(str) > 512) {
			printf("Cok uzun bir komut satiri\n" );
			continue;
		}

		//tek komutmu çoğul komut mu
		e_flag = process_str(str,  parsedArgs, parsedPipedArgs3);

		//tekil komut
		if (e_flag == 1){
			int pid_variable = exec_cmd(parsedArgs);
			if(pid_variable != 1 || pid_variable != 0){
				append(pid_variable);
			}
		}
		//cogul komut
		if (e_flag == 2)
			exec_cmd_piped3(parsedArgs, parsedPipedArgs3);
	}

	return 0;
}