#include "holberton.h"

/**
 * _execute - a child process is created to execute prompt
 * @tokens: characters of each token
 * @line: command line obtained from user
 * Return: N/A, action execute
 */

void _execute(char **tokens, char *line)
{
	pid_t pid;
	int status;
	list_tt *list;
	char *path;

	if (tokens[0] == NULL)
		/* An empty command was entered. */
		return;
	if (tokens[0][0] == 'e' && tokens[0][1] == 'x'
	    && tokens[0][2] == 'i' && tokens[0][3] == 't')
	{
		free(tokens);
		free(line);
		_exit(0);
	}
	list = _build_list();
	path = _path(tokens, list);
	pid = fork(); /*child process starts at this call */
	if (pid < 0)
		perror("Fork did not succeed: ");
	if (pid == 0)/* child processes */
	{
		if (execve(path, tokens, environ) == -1)
		{
			free(path);
			free_list(list);
			perror("error");
		}

	}
	else /* parent process */
		pid = wait(&status);
	free(path);
	free_list(list);
}
