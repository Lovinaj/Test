#include "shell.h"

/**
 * command_not_found - Handle and print "command not found" error.
 * @arrayStr: Array of strings containing the command and its arguments.
 * @argv: Array of strings containing the name of the shell and its arguments.
 *
 * This function writes an error message to stderr indicating that the
 * specified command was not found.
 */
void command_not_found(char **arrayStr, char **argv)
{
	write(2, argv[0], _strlen(argv[0]));
	write(2, ": ", 2);
	write(2, "1: ", 4);
	write(2, arrayStr[0], _strlen(arrayStr[0]));
	write(2, ": not found\n", 12);
}
