#include "holberton.h"

void _command(char **t)
{
	pid_t pid;
	int status;
	
	pid = fork(); /*child process starts at this call */
	if (t[0][0] == 'e' && t[0][1] == 'x' && t[0][2] == 'i' && t[0][3] == 't')
	{
		exit(EXIT_SUCCESS);
	}
	if (pid < 0)
	{
		perror("Fork did not succeed: ");
	}
	if (pid == 0)
	{
		_path(t);
	}
	else
	{
		pid = wait(&status);
	}

}
