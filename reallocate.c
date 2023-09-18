#include "shell.h"

/**
 * _realloc - reallocate a memory space
 * @ptr: pointer to the previously allocated memory using malloc
 * @new_size: newsize of the memory
 *
 * Return: NULL if unable to realllocate
 */

void *_realloc(void *ptr, size_t new_size)
{
	char *src, *dest;
	void *new_ptr;
	size_t i;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);

	if (!new_ptr)
		return (NULL);

	if (ptr != NULL)
	{
		src = ptr;
		dest = new_ptr;
		for (i = 0; i < new_size; i++)
		{
			dest[i] = src[i];
		}

		free(ptr);
	}

	return (new_ptr);
}
