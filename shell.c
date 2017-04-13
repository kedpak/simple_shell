#include "holberton.h"
#include <signal.h>

static void sigHandler(int sig)
{
	if (sig == SIGINT)
	{
		_putstring("\n");
		_putstring(PROMPT);
	}
	
}

char _putstring(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	return (0);
}

int main(int agrc, char *argv[], char *envp[])
{
	size_t n, g_line;
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
		if (signal(SIGINT, sigHandler) == SIG_ERR)
			perror("signal error");
		g_line = getline(&line, &n, stdin);
		toke = malloc(sizeof(char) * 300);
	       	line[g_line - 1] = 0; /* placing null character at end of the line */
		token = strtok(line, " \n\t\r"); 
		i = 0;
		while (token != NULL)
		{
			toke[i] = token;
			token = strtok(NULL, " \n\t\r;"); 
			i++;
		}
		toke[i] = NULL;
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
	       	free(toke);
	}
	return (0);
}
