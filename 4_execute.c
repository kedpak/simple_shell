#include "holberton.h"

void _execute(char **tokens)
{
	pid_t pid;
	int status;

	if (tokens[0] == NULL)
		/* An empty command was entered. */
		return;

	pid = fork(); /*child process starts at this call */
	if (tokens[0][0] == 'e' && tokens[0][1] == 'x' && tokens[0][2] == 'i' && tokens[0][3] == 't')
		_exit(0);
	if (pid < 0)
		perror("Fork did not succeed: ");
	if (pid == 0)/* child processes */
	{
		_path(tokens);
	}
	else /* parent process */
		pid = wait(&status);
}
