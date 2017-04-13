#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"
extern char **environ;


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
}


list_tt *add_node_end(list_tt **head, char *str)
{

	char *temp = str;
	list_tt *new_node;
	list_tt *head_node;

	if (str == NULL)
	{
		return (NULL);
	}
	head_node = *head;
	new_node = (list_tt *)malloc(sizeof(list_tt)); 
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->string = temp;
	if (new_node->string == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		while (head_node->next != NULL)
		{
			head_node = head_node->next;
		}
		head_node->next = new_node;
		new_node->next = NULL;
		return (new_node);
	}
	return (NULL);
}

/*
 * _build_list - puts the PATH directories into linked lists
 * Return: node of string with data of string input
 */
list_tt *_build_list(void)
{
	char *string = _getenv("PATH");
	const char b[2] = ":";
        char *token; 
/*	struct path_list *new_node = malloc(sizeof(list_tt)); */
	list_tt *node; 
	/* need function to count dirs in PATH if(str[i] == ':' or '\0' count++*/

	/* temp = malloc(sizeof(char *)*how_many dirs in PATH + 1 for NULL)*/

	/* for (i = 0; token != NULL; i++) use strdup(temp[i], token) temp[i] = NULL*/

	/* return temp */
        token = strtok(string, b);
	node = NULL;
        while (token != NULL)
        {
		add_node_end(&node, token);
		token = strtok(NULL, b);

	}
	return (node);
}

/*
int main(void)
{
	_build_list();
	return (0);
}

*/
