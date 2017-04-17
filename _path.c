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
				_putstring("-bash: ");
				_putstring(t[0]);
				_putstring(": No such file or directory\n");
				_exit(98);
			}
		}
		path = strcpy(path, yay->string);
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
                        _putstring(t[0]);
                        _putstring(": command not found\n");
			_exit(98);
			free(path);
                }
	}
	free(path);
	free(head);
}
