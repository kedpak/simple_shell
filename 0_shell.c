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

void main(void)
{
	int pipe, _builtinCheck;
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
/*		builtinCheck = _builtins(tokens);
		if (builtinCheck != 1)*/
			_execute(tokens);
		if (pipe == 1)
			break;
	}
	free(line);
	free(tokens);
	_exit(0);
}
