#include "holberton.h"

/**
 * _path - handles concatination of input and path directories
 * @t: string inputed into command line
 * Return: void
 */
void _path(char **t)
{

	list_tt *tmp_node, *head;
	char *path;
	int file, buffer;

	buffer = BUFSIZE;
	head = _build_list();
	path = malloc(sizeof(char) * buffer);
	tmp_node = head;
	while (1)
	{
		_pathhelper(file, t);
		path = _strcpy(path, tmp_node->str);
		path = _strcat(path, t[0]);
		file = access(path, X_OK);
		if (file == 0)
		{
			if (execve(path, t, environ) == -1)
				perror("error");
			free(path);
			free(head);
		}
		tmp_node = tmp_node->next;
		if (tmp_node->next == NULL)
		{
			_errorstring(t[0]);
			_errorstring(": command not found\n");
			free(path);
			free(head);
			_exit(98);
		}
	}
	free_list(head);
	free(path);
}

/**
 * _pathhelper - handles case if input begins with '/'
 * @file: checks if specific path file is found
 * @t: inputed string in command line
 * Return: void
 */
void _pathhelper(int file, char **t)
{
	if (t[0][0] == '/')
	{
		file = access(t[0], X_OK);
		if (file == 0)
			execve(t[0], t, environ);
		else
		{
			_errorstring("-bash: ");
			perror(t[0]);
			_exit(98);
		}
	}

}
