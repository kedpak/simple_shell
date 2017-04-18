#include "holberton.h"



void _path(char **t)
{
        list_tt *yay, *head;
        char *path;
        int file;

        head = _build_list();
        path = malloc(100);
        yay = head;
        while (1)
        {
		if (t[0][0] == '/')
		{
			file = access(t[0], X_OK);
			if (file == 0)
			{ 
				execve(t[0], t, environ);
				_exit(98);
			}
			else
			{
				perror(t[0]);
				_exit(98);
			}
		}
		path = _strcpy(path, yay->string);
                path = _strcat(path, t[0]);
                file = access(path, X_OK);
                if (file == 0)
                {
                        if (execve(path, t, environ) == -1)
                        {
                                perror("error");
                        }
			free(path);
		}
                yay = yay->next;
                if (yay->next == NULL)
                {
			_errorstring(t[0]);
                        _errorstring(": command not found\n");
			_exit(98);
			free(path);
                }
	}
	free(path);
	free(head);
}
