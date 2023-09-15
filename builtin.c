#include "shell.h"

/**
 * execute_args - Execute a built-in command or create a new process.
 * @args: The command and its arguments.
 *
 * Return: 1 on success, 0 on failure.
 */
int execute_args(char **args)
{
	size_t i = 0;
	char *builtin_func_list[] = {"cd", "env", "help", "exit"};

	int (*builtin_func[])(char **) = {&my_cd, &my_env, &my_help, &my_exit};

	/* find if the command is a builtin */
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
	/* if there is a match execute the builtin command */
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			(*builtin_func[i])(args);
			return (0);
		}
	}
	return (1);
}

/**
 * my_cd - Change the current working directory.
 * @args: Array of command arguments.
 *
 * Return: 1 on success, 0 on failure.
 */
int my_cd(char **args)
{
	const char *home_dir;

	if (args[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			write(2, "cd: HOME not set", 16);
			return (0);
		}
	}
	else
		home_dir = args[1];

	if (chdir(home_dir) != 0)
	{
		perror("cd");
		return (0);
	}
	return (1);
}

/**
 * my_env - Display environment variables.
 * @env: enviroment variables
 *
 * Return: Always returns 1.
 */
int my_env(char *env[])
{
	int i = 0;

	if (env == NULL)
		return (0);
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (1);
}

/**
 * my_help - Display a help message.
 * @args: Array of command arguments.
 *
 * Return: Always returns 1.
 */
int my_help(char **args)
{
	(void)args;
	printf("Simple Shell - Help:\n");
	printf("cd [DIRECTORY] - Change the current directory\n");
	printf("env - Display environment variables\n");
	printf("help - Display this help message\n");
	printf("exit - Exit the shell\n");
	return (1);
}

/**
 * my_exit - Exit the shell.
 * @args: Array of command arguments.
 *
 * Return: Always returns 0 to signal the shell to exit.
 */
int my_exit(char __attribute__((unused))**args)
{
	/* this value will be used to know if exit was entered */
	return (-3);
}

