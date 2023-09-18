#include "shell.h"

/**
 * getLine - Read a line of input from the user.
 * @buffer: A buffer to store the input line.
 * @status: The exit status in case of an error.
 *
 * This function reads a line of input from the user and stores it in the
 * provided buffer. It returns the buffer with the newline character removed.
 * If an error occurs, it frees the buffer, exits the program with the given
 * status, and handles terminal-specific behavior.
 *
 * Return: A pointer to the input line (buffer) without the newline character,
 *          or NULL in case of error.
 */
char *getLine(char *buffer, int status)
{
	int flag;
	size_t n;

	/* Read user input */
	flag = getline(&buffer, &n, stdin);
	if (flag == -1)
	{
		free(buffer);
		if (isatty(0) == 1)
			exit(0);
		exit(status);
	}

	buffer[_strlen(buffer) - 1] = '\0';
	return (buffer);
}
