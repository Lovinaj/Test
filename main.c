#include "shell.h"

/**
 * main - Entry point
 * @argc: Agument count
 * @argv: Argument vector
 * @env: Environment variable from parent
 * Return: Always 0
 */

int main(int argc, char **argv, char *env[])
{
	prompt(argc, argv, env);

	return (0);
}
