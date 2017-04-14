#include "holberton.h"
#include <signal.h>

/**
 * sigHandler - checks signal for ^C
 * @sig: signal value compared sigal flag SIGINT
* Return: N/A, skip to newline if ^C is entered
*/

static void sigHandler(int sig)
{
	if (sig == SIGINT)
	{
		_putstring("\n");
		_putstring(PROMPT);
	}
}

/**
 * main - main function for the shell
* Description: There are currently 3 main function that perform basic
* shell actions:
* 1) _getline: get the user input
* 2) tokenize: sperate input into tokens to be checked
* 3) _execute: checks PATH for to see if tokens match with any files
* (Not include before): check for aliases and built-ins
* Return: N/A, exit 0 on success
*/

int main(void)
{
	int pipe;/*int _builtinCheck;*/
	char *line, **tokens;
	struct stat sb;

	pipe = 0;
	if (fstat(STDIN_FILENO, &sb) == -1)
	{
		perror("status fail");
		_exit(1);
	}
	if ((sb.st_mode & S_IFMT) == S_IFIFO)
		pipe = 1;
	while (1)
	{
		if (pipe == 0)
			_putstring(PROMPT);
		if (signal(SIGINT, sigHandler) == SIG_ERR)
		{
			perror("signal error");
			_exit(1);
		}
		line = _getline();
		tokens = tokenize(line);
/*		builtinCheck = _builtins(tokens);*/
/*		if (builtinCheck != 1)*/
		_execute(tokens, line);
		if (pipe == 1)
			break;
		free(line);
		free(tokens);
	}
	_exit(0);
}
