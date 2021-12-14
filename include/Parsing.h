#ifndef __PARSING_H__
#define __PARSING_H__


#include <stdio.h>
#include <stdlib.h>
#include<string.h>



#define semicolon  ";"
#define space  " "
#define endl "\n"
#define prompt  "\nmatrix> "
#define MAXCHAR  512
#define MAXLINE  256


//COLORS
#define RESET_COLOR() printf("\x1B[0m")
#define BLACK() printf("\x1B[30m")
#define RED() printf("\x1B[31m")
#define GREEN() printf("\x1B[32m")
#define YELLOW() printf("\x1B[33m")
#define BLUE() printf("\x1B[34m")
#define MAGNETA() printf("\x1B[35m")
#define CYAN() printf("\x1B[36m")



int process_str(char* input,
                char** parsedArgs,
                char* parsedPipedArgs[MAXLINE][MAXLINE]); // gelen stringi parcalara ayirmak icin

/*char * trim_whitespaces(char* str);// bolsuklari trimlemek icin*/

int split_semicolon(char* str, char** splitted);
int split_line(char* str, char** splitted);  // dosyada satirleri ayrıştırmak
void split_Space(char *str, char** splitted); // bosluklari ayirmak
int split_semicolon2(char* str, char** splitted); // ; lere göre ayirma
int count_char(char * const line, char s); // bir stringteki belirtilen karakterden kaç tane oldugunu söyleyen fonksiyon
#endif