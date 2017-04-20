#include "holberton.h"


/**
 * _realloc - reallocate memory from old block to new
 * @ptr: pointer to old allocated memory
 * @old_size: size of old allocation
 * @new_size: size of new allocation
 * Return: pointer to new memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	unsigned int i;
	char *ptrcpy;

	if (ptr == NULL)
	{
		new = malloc(new_size);
		if (new == NULL)
		{
			return (NULL);
		}
		return (new);
	}
	if (new_size == old_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(sizeof(char) * (new_size));
	ptrcpy = ptr;
	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
		{
			new[i] = ptrcpy[i];
		}
	}
	else
	{
		for (i = 0; i < new_size; i++)
		{
			new[i] = ptrcpy[i];
		}
	}
	free(ptrcpy);
	return (new);
}
