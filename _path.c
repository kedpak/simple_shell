#include "holberton.h"



char *_path(char **t, list_tt *list)
{
        list_tt *tmp_node, *head;
        char *path;
        int file, buffer;

        buffer = BUFSIZE;
	head = list;
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
		_strcpy(path, tmp_node->str);
		_strcat(path, t[0]);
                file = access(path, X_OK);
                if (file == 0)
                {
			return (path);
		}
                tmp_node = tmp_node->next;
                if (tmp_node->next == NULL)
                {
			free(path);
			free(head);
			_errorstring(t[0]);
                        _errorstring(": command not found\n");
			_exit(1);
                }
	}
	free_list(head);
	free(path);
}
