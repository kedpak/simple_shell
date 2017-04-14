#include "holberton.h"

int _strlen(const char *s)
{
        int i = 0;

        while (s[i] != '\0')
        {
                i++;
        }
        return (i);
}

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);

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
