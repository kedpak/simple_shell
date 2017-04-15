#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
extern char **environ;
#define PROMPT "$ "

/**
 * struct path_list - linked list for path
 * @str: string of path directory
 * @len: length path directory
 * @next: points to next node
 */
typedef struct path_list
{
	char *str;
	unsigned int len;
	struct path_list *next;
} list_tt;

/* Constants */
#define BUFSIZE 1024
#define TOK_BUFSIZE 64
#define DELIM " \"\n\t\r;"
/* functions */
char *_getline(void);
char _errorstring(char *str);
char **tokenize(char *line);
void _execute(char **tokens);
int _my_exit(void);
int _strlen(const char *s);
int _print_path(void);
int _setenv(const char *name, const char *value, int overwrite);
size_t print_list(const list_tt *h);
list_tt *_build_list(void);
list_tt *add_node_end(list_tt **head, const char *str);
char *_getenv(const char *name, char *mem);
void _path(char **t);
char *_strcat(char *dest, char *src);
char _putstring(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void free_list(list_tt *head);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _pathhelper(int file, char **t, list_tt *list, char *path);
#endif
