#include "holberton.h"

/**
 * _getenv - finds the directories within the PATH variable and tokenizes them
 * @name: "PATH" - the PATH variable in the environment
 * @mem_copy: a copy of the directories to be used
 * Return: tokenized path
 */

char *_getenv(const char *name, char *mem_copy)
{
	int i, j, len;
	const char s[2] = "=";
	char *token, *copy;

	copy = mem_copy;
	i = j = 0; len = _strlen(name);
	while (environ[i] != NULL)
	{
		if (environ[i][0] == name[0])
		{
			while (environ[i][j] != '\0' && environ[i][j] == name[j])
			{
				j++;
				if (len == j)
				{
					copy = _strcpy(copy, environ[i]);
					token = strtok(copy, s);
					token = strtok(NULL, s);
					return (token);
				}
			}
		}
		i++;
	}
	return (NULL);
}
