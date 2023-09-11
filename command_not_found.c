#include "shell.h"

void command_not_found(char **arrayStr, char **argv)
{
	write(2, argv[0], _strlen(argv[0]));
	write(2, ": ", 2);
	write(2, "1: ", 3);
	write(2, arrayStr[0], _strlen(arrayStr[0]));
	write(2, ": not found\n", 12);
}
