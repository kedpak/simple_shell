#include "holberton.h"
extern char **environ;

char *_getenv(const char *name)
{

        int i = 0;
        int len = _strlen(name);
        int j = 0;
        const char s[2] = "=";
        char *token;
	char *copy = malloc(100);
	

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

        return (0);
}
