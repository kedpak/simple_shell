#include "holberton.h"

char _putstring(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

int main(int agrc, char *argv[], char *envp[])
{
	ssize_t n, g_line;
	int status;
	pid_t pid;
        char *token, *line;
	char **toke;
	unsigned int i;

	n = 0;
	line = NULL;
	while (98)
	{
		_putstring(PROMPT);
		g_line = getline(&line, &n, stdin);
		toke = malloc(sizeof(char) * 300);
	       	line[g_line - 1] = 0; /* placing null character at end of the line */
		token = strtok(line, " "); 
		i = 0;
		while (token != NULL)
		{
			toke[i] = token;
			token = strtok(NULL, " \n\t\r"); 
			i++;
		}
		pid = fork(); /*child process starts at this call */
		if (pid < 0)
		{
			perror("Fork did not succeed: ");
		}
		if (pid == 0)
		{
			_path(toke);
		}
		else
		{
			pid = wait(&status);
		}
	}
	return (0);
}

