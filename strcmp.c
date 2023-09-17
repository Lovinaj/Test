#include "shell.h"
/**
* _strcmp - function that compares two strings
* @s1: strings
* @s2: strings
* Return: value less than 0 or greater than 0
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int j;

	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	j = s1[i] - s2[i];
	return (j);
}
