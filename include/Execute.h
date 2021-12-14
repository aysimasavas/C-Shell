#ifndef __EXECUTE_H_
#define __EXECUTE_H_

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Parsing.h"


int array_size;

long* pid_array;



int exec_cmd(char **parsed);  // komut calistirir
void exec_cmd_piped3(char **parsed, char * parsedpipe[MAXLINE][MAXLINE]); // sirali komut calistirir
void help_open(); // yardim
int own_cmd_handler(char ** parsed); // ozel komutlar



//own commands
void clear(); // ekrani temizler
void m_exit(); // kapatır
void changeDirectory(); // CD komutu



#endif