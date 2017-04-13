#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;
#include "holberton.h"
#define PROMPT "$ "

/*
int _strlen(const char *s)
{
        int i = 0;

        while (s[i] != '\0')
	{
	i++;
	}
        return (i);
}
*/

/*
size_t print_list(const list_tt *h)
{
        size_t i = 0;

        while (h != NULL)
        {
                i++;
                printf("%s\n", h->string);
                h = h->next;
        }

        return (i);
	}*/

char _putstring(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	/* gets the length of src string*/
	while (dest[i] != '\0')
	{
		i++;
	}
	dest[i] = '/';
	i++;
	while (src[j] != '\0')
	{
	
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int main(int agrc, char *argv[], char *envp[])
{
	list_tt *path_list;
	char *line = NULL;
	ssize_t n = 0;
	int status, file;
	ssize_t g_line;
	pid_t pid;
        char *token;
	char **toke;
	unsigned int i;
	list_tt *head = _build_list();
	list_tt *yay;
	yay = head;
/*	const char *cat; */
/*	char path_str[20] = yay->string;*/
	char *test2;
	char *path;
	
	path = malloc(100);
	while (98)
	{
		_putstring(PROMPT);
		g_line = getline(&line, &n, stdin);
		toke = malloc(sizeof(char) * 30);
		line[g_line - 1] = 0; /* placing null character at end of the line */

		token = strtok(line, " "); 
		i = 0;
		while (token != NULL)
		{
			toke[i] = token;
			token = strtok(NULL, " \n\t\r"); /*tokenizing with space, newlne, tab, and return */
			i++;
		}
		pid = fork(); /*child process starts at this call */
		if (pid < 0)
		{
			perror("Fork did not succeed: ");
		}
		if (pid == 0)
		{
			while (yay->next != NULL)
			{
				printf("Before: %s\n", yay->string);
				path = strcpy(path, yay->string);
				path = _strcat(path, "/");
				path = _strcat(path, toke[0]);
				path = strcat(path, "\0");
				file = access(path, X_OK);

				if (file == 0)
				{
					printf("entered\n");
					if (execve(path, toke, envp) == -1)
					{
						perror("error\n");
					}
				}
				yay = yay->next;
			}
		}
		else
		{
			pid = wait(&status);
		}
	}
	return (0);
}

