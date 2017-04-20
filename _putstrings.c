#include "holberton.h"

/**
 * _putstring - prints out string in standard ouput
 * @str: string to be printed
 * Return: zero
 */
char _putstring(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	return (0);
}

/**
 * _errorstring - prints out string in standard error
 * @str: string to be printed
 * Return: zero
 */
char _errorstring(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
	return (0);
}
