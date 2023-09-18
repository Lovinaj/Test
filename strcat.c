#include "shell.h"

/**
 *  _strcat - Concatenates two strings.
 * @dest: This is the destination string.
 * @src: This is the source string to be appended.
 * Return: A pointer to the concatenated string @str1
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = NULL;

	ptr = dest;

	while (*ptr)
	{
		ptr++;
	}

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}
