#include "holberton.h"


char *_getline(void)
{
	char *line; /* line is freed in the main function */
	ssize_t buffer, g_line;
/*TODO look at mallocing for char *line */	
	line = NULL, buffer = 0;
	g_line = getline(&line, &buffer, stdin);/* getline mallocs with buffer*/
	if (g_line == EOF)
		_exit(0);
	line[g_line - 1] = 0; /* placing null character at end of the line */
	return (line);
}
