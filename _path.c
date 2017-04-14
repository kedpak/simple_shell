#include "holberton.h"

void _path(char **t)
{
        list_tt *path_list, *yay, *head;
        char *path;
        int file;

        head = _build_list();
        path = malloc(100);
        yay = head;
        while (1)
        {
                path = strcpy(path, yay->string);
                path = _strcat(path, t[0]);
                file = access(path, X_OK);
                if (file == 0)
                {
                        if (execve(path, t, environ) == -1)
                        {
                                perror("error");
                        }
                }
                yay = yay->next;
                if (yay->next == NULL)
                {
                        _putstring(t[0]);
                        _putstring(": command not found\n");
                        _exit(98);
                }
        }
}
