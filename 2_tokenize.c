#include "holberton.h"
#include "holberton.h"

char **tokenize(char *line)
{
	int bufsize, position;
	char **tokens, *token; /* will need to be freed in main function */ /*the characters of each token */
/* token = the words (strings), no malloc (see comment below */

	bufsize = TOK_BUFSIZE, position = 0;
	tokens = malloc(bufsize * sizeof(char*));
	if (!tokens)
	{
		perror("allocation error\n");
		_exit(1);
	}
	token = strtok(line, DELIM);/* tokenize words via delimeters */ 
	while (token != NULL)
	{
		tokens[position] = token; /* since token is ref, no malloc */
		position++;

/************** resize buffer ************************/
		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = _realloc(tokens, bufsize * sizeof(char*), bufsize * sizeof(char*));  /****** TODO add custom realloc *******/
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
