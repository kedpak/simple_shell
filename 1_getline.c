#include "holberton.h"

/**
 * _getline - gets line reads input from command line
 * Return: void
 */

char *_getline(void)
{
	char *line; /* line is freed in the main function */
	size_t buffer;
	ssize_t g_line;

	line = NULL, buffer = 0;
	g_line = getline(&line, &buffer, stdin);/* getline mallocs with buffer*/
	if (g_line == EOF)
	{
		free(line);
		_exit(1);
	}
	line[g_line - 1] = 0; /* placing null character at end of the line */
	return (line);
}
