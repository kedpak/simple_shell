#include "holberton.h"



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
		if (t[0][0] == '/')
		{
			file = access(t[0], X_OK);
			if (file == 0)
				execve(t[0], t, environ);
			else
			{
				perror(t[0]);
				_exit(98);
			}
		}
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
			_putstring(t[0]);
                        _putstring(": command not found\n");
			free(path);
			free(head);
			_exit(98);
                }
	}
	free_list(head);
	free(path);
}
