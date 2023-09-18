#include "shell.h"

/**
 * parse - parses the line read into command line arguments
 *
 * @line: the line to tokenize
 *
 * Return: return a list of all strings passed from the command line
 */
char **parse(char *line, char *delimiter)
{
	char *token = NULL;
	char **arrayStr = NULL;
	int i, buffsize = BUFFSIZE_STD;


	arrayStr = malloc(sizeof(char *) * buffsize);
	if (arrayStr == NULL)
	{
		perror("Memory allocation for list of tokens");
		exit(EXIT_FAILURE);
	}
	token = _strtok(line, delimiter);
	if (token == NULL)
	{
		free(token);
		free(arrayStr);
		return (NULL);
	}
	for (i = 0; token != NULL; i++)
	{
		if (i >= buffsize)
		{
			buffsize += BUFFSIZE_STD;
			/* Reallocate memory for the arrayStr array with the new buffer size */
			arrayStr = _realloc(arrayStr, buffsize * sizeof(char *));
			if (arrayStr == NULL)
			{
				perror("Memory reallocation failed");
				free(arrayStr);
				free(token);
				exit(EXIT_FAILURE);
			}
		}
		arrayStr[i] = token;
		token = _strtok(NULL, delimiter);
	}
	arrayStr[i] = NULL;
	free(token);
	return (arrayStr);
}
