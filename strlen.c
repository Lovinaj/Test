#include "shell.h"
/**
 * _strlen -This Calculates the length of a string.
 * @str: The input string.
 * Return: The length of the string (excluding the null terminator)
 */

size_t _strlen(const char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}
