#include "holberton.h"
#include "holberton.h"

/**
 * tokenize - seperate array of token (aka tokens) from _getline function
 * @line: array of strings (tokens)
* Return: array of characters associated with tokens ex: characters in /bin/ls
*/

char **tokenize(char *line)
{
	int bufsize, position;
	char **tokens, *token; /*freed in main function */

	bufsize = TOK_BUFSIZE, position = 0;
	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		perror("allocation error\n");
		_exit(1);
	}
	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
/************** resize buffer ************************/
		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZ
				tokens = _realloc(tokens,
						  (bufsize - TOK_BUFSIZE) * sizeof(char *),
						  bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("allocation error\n");
				_exit(-1);
			}
		}
/****************************************************/
		token = strtok(NULL, DELIM);
	}
	free(token);
	tokens[position] = NULL;
	return (tokens);
}
