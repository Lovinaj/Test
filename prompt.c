#include "shell.h"

/**
 * prompt - Displays a prompt and processes user input
 *
 * @argc: the argument counter
 * @argv: pointer to the commad line arguments entered
 * @env: the environment variable
 *
 * Return: always return 0
*/

int prompt(int argc, char *argv[], char **env)
{
	int status = 0;
	char *buffer = NULL, *line;
	char **receivedArgs;

	/* loop through to always display the dollar($) prompt */
	while (argc)
	{
		if (isatty(0) == 1)
			write(1, "$ ", 3);
		/* read line using function */
		line = getLine(buffer, status);

		receivedArgs = parse(line, DELIM);

		/* when no argument is parsed, parse returns NULL */
		if (receivedArgs != NULL)
		{
			status = accessCommand(receivedArgs, argv, env);
		}

		free(receivedArgs);
		free(line);
		if (status == -3)
			exit(0);
	}
	return (status);
}
