#include "shell.h"

/**
 * get_path - Get the PATH environment variable as a duplicated string.
 * @arrayStr: Array of strings containing the command and its arguments.
 *
 * This function retrieves the PATH environment variable and returns it as
 * a duplicated string. The caller is responsible for freeing the memory
 * allocated for the duplicated string when it's no longer needed.
 *
 * Return: A pointer to the duplicated PATH string, or NULL on failure.
 */
char *get_path(char **arrayStr)
{
	char *path, *path_dup;

	if (arrayStr == NULL)
		return (NULL);

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_dup = strdup(path);

	return (path_dup);
}
