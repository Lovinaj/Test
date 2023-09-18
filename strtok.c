#include "shell.h"
/**
 * _strtok - A function to tokenize a string.
 * @str: The string to be tokenized.
 * @delim: The delimiter character(s) used for tokenization.
 *
 * Return: A pointer to the next token found in the string, or NULL if no
 * more tokens are found.
 */

char *_strtok(char *str, const char *delim)
{
	char *saved_ptr = NULL;
	char *token;

	if (str == NULL)
	{
		str = saved_ptr;
	}

	while (*str != '\0' && _strchr(delim, *str) != NULL)
	{
		str++;
	}

	if (*str == '\0')
	{
		saved_ptr = NULL;
		return (NULL);
	}

	token = str;
	while (*str != '\0' && _strchr(delim, *str) == NULL)
	{
		str++;
	}

	if (*str != '\0')
	{
		*str = '\0';
		saved_ptr = str + 1;
	}
	else
	{
		saved_ptr = str;
	}

	return (token);
}
