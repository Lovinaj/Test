#include "shell.h"

/**
 * _strdup - A function to duplicate a string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to a newly allocated memory block containing a copy of
 * the string 'str', or NULL if memory allocation fails or 'str' is NULL.
 */
char *_strdup(const char* str)
{
	size_t len;
	char *dup;

	if (str == NULL)
		return NULL;

	len = strlen(str) + 1;
	dup = malloc(len);

	if (dup == NULL)
		return NULL;

	_memcpy(dup, str, len);

	return dup;
}
