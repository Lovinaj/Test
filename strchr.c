#include "shell.h"

/**
 * _strchr - A function to locate a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: A pointer to the first occurrence of the character 'c' in the
 * string 's', or NULL if the character is not found.
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}

	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
