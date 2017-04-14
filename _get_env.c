#include "holberton.h"
extern char **environ;

char *_getenv(const char *name, char *mem_copy)
{
        int i, j, len;
        const char s[2] = "=";
        char *token, *copy;
	
/* TODO add buffer resize */
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
					copy = _strcpy(copy,environ[i]);
                                        token = strtok(copy, s);
                                        token = strtok(NULL, s);
                                        return(token);
                                }
                        }
                }
                i++;
        }
        return (NULL);
}
