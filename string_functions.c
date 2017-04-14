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
		++i;
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

/**
 * _strdup - returns a copy of a string passed
 * @str: string passed
(* a blank line
* Description: Longer description of the function)?
(* section header: Section description)*
* Return: return copy string, NULL otherwise
*/

char *_strdup(const char *str)
{
	int len, i;
	char *a;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	a = malloc(len * sizeof(char) + 1);
	if (a == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		a[i] = str[i];
	}
	a[i] = '\0';
	return (a);
}

char _putstring(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	return (0);
}

char _errorstring(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
	return (0);
}
