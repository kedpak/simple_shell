#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "holberton.h"

/**
 * print_list - prints all elements of a linked list
 * @h: node input
 * Return: node count
 */
size_t print_list(const list_tt *h)
{
	size_t i = 0;

	for (i = 0; h != NULL; h = h->next, i++)
	{
		printf("%s\n", h->str);
	}
	return (i);
}

/**
 * add_node_end - add a new node at the end of a linked list
 * @head: pointer to head of linked list
 * @str: string copied and added to new node
 * Return: addess of new element with new node
 */

list_tt *add_node_end(list_tt **head, const char *str)
{
	list_tt *tmp_node, *new_node = malloc(sizeof(list_tt));

	if (new_node == NULL)
		return (NULL);
	new_node->str = _strdup(str);
	new_node->len = _strlen(str);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	tmp_node = *head;
	while (tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	tmp_node->next = new_node;
	return (new_node);
}

/**
 * _build_list - puts the PATH directories into linked lists
 * Return: node of string with data of string input
 */

list_tt *_build_list(void)
{
	char *dir, *full_path, *copy_path;
	list_tt *head;

	copy_path = malloc(100);
	full_path = _getenv("PATH", copy_path);
	dir = strtok(full_path, ":");
	head = NULL;
	while (dir != NULL)
	{
		add_node_end(&head, dir);
		dir = strtok(NULL, ":");

	}
	free(copy_path);
	return (head);
}

/**
 * free_list - frees linked list list_t from memory
 * @head: pointer to head of linked list
 * Return: N/A, void function
 */
void free_list(list_tt *head)
{
	list_tt *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
