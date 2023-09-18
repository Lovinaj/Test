#include "shell.h"

/**
 * _memcpy - A function to copy memory area.
 * @dest: A pointer to the destination memory area.
 * @src: A pointer to the source memory area.
 * @size: The number of bytes to copy.
 *
 * Return: A pointer to the destination memory area 'dest'.
 */
void *_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char *dest_ptr;
	const unsigned char *src_ptr = (const unsigned char *)src;
	size_t i;

	if (dest == NULL || src == NULL)
		return (NULL);

	dest_ptr = (unsigned char *)dest;

	for (i = 0; i < size; i++)
		dest_ptr[i] = src_ptr[i];

	return (dest);
}
