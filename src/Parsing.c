#include "Parsing.h"

int process_str(char* input, char** parsedArgs, char*parsedPipedArgs[MAXLINE][MAXLINE]) {

	char *strpiped[MAXLINE];
	int piped = 0;
	//piped sirali mi yoksa tekil kod var mi diye kontrol ediyor
	piped = split_semicolon2(input, strpiped);
	if (piped)
	{
		int i;
		for (i = 0; i < MAXLINE; ++i)
		{
			if (strpiped[i] == NULL)
				break;
			split_Space(strpiped[i], parsedPipedArgs[i]);
		}
	} else {
		split_Space(strpiped[0], parsedArgs);

	}
	return 1 + piped;
}

int split_line(char* str, char** splitted) {
	int i;

	for (i = 0; i < MAXLINE; i++) {
		splitted[i] = strsep(&str, endl);

		if (splitted[i] == NULL)
			break;
		if (strlen(splitted[i]) == 0)
			i--;
	}
}
void split_Space(char *str, char** splitted) {
	int i;

	for (i = 0; i < MAXLINE; i++) {
		splitted[i] = strsep(&str, space);

		if (splitted[i] == NULL)
			break;
		if (strlen(splitted[i]) == 0)
			i--;
	}
}
int split_semicolon2(char* str, char** splitted) {

	int i;

	for (i = 0; i < MAXLINE; i++) {
		splitted[i] = strsep(&str, semicolon);

		if (splitted[i] == NULL)
			break;
		if (strlen(splitted[i]) == 0)
			i--;
	}
	if (splitted[1] == NULL)
		return 0; // sirali komut yoksa 0 doner
	else {
		return 1;
	}
}
int count_char(char * const line, char s)
{
	int index = 0;
	int count = 0;

	while (line[index])
	{
		if (line[index] == s)
			count++;
		index++;
	}
	return count;
}