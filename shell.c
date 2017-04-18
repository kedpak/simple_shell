#include "holberton.h"

char _putstring(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	return (0);
}

int main(void)
{
	size_t n, g_line;
	int pipe;
        char *token, *line;
	char **toke;
	unsigned int i;
	struct stat sb;

	n = 0;
	pipe = 0; 
	line = NULL;
	if (fstat(STDIN_FILENO, &sb) == -1)
	{
		perror("status fail");
		exit(EXIT_FAILURE);
		     
	}
	if ((sb.st_mode & S_IFMT) == S_IFIFO)
	{
		pipe = 1;
	}
	_putstring(PROMPT);
	while (1)
	{
		_putstring(PROMPT);
		g_line = getline(&line, &n, stdin);
		toke = malloc(sizeof(char) * 300);
		line[g_line - 1] = 0; /* placing null character at end of the line */
		token = strtok(line, " \n\t\r"); 
		i = 0;
		while (token != NULL)
		{
			toke[i] = token;
			token = strtok(NULL, " \n\t\r"); 
			i++;
		}
		toke[i] = NULL;
		_command(toke);
		if (pipe == 1)
		{
			break;
		}
		free(toke);
	}
	exit(EXIT_SUCCESS);
}

