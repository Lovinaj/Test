#include "shell.h"

/**
 * execute_args - Execute a built-in command or create a new process.
 * @args: The command and its arguments.
 * @env: enviroment variables
 * Return: 1 on success, 0 on failure.
 */
int execute_args(char **args, char **env)
{
	size_t i = 0;
	char *builtin_func_list[] = {"cd", "env", "help", "exit"};

	int (*builtin_func[])(char **) = {&my_cd, &my_env, &my_help, &my_exit};

	/* find if the command is a builtin */
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		if (_strcmp(args[0], "env") == 0)
			return (my_env(env));
		/* if there is a match execute the builtin command */
		if (_strcmp(args[0], builtin_func_list[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (-1);
}

/**
 * my_cd - Change the current working directory.
 * @args: Array of command arguments.
 *
 * Return: 1 on success, 0 on failure.
 */
int my_cd(char **args)
{
	const char *dir;
	char *prev_dir = NULL;

	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{
		dir = getenv("HOME");
		if (dir == NULL)
			dir = getenv("PWD");
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		dir = getenv("_OLDPWD");
		if (dir == NULL)
			dir = getenv("PWD");
	}
	else
		dir = args[1];

	prev_dir = getcwd(prev_dir, 0);
	if (chdir(dir) != 0)
	{
		perror("cd");
		free(prev_dir);
		return (1);
	}
	setenv("_OLDPWD", prev_dir, 1);
	free(prev_dir);
	return (0);
}

/**
 * my_env - Print environment variables.
 * @env: Array of strings containing environment variables.
 *
 * This function prints the environment variables one by one.
 *
 * Return: 0 on success, 1 if the env array is NULL.
 */
int my_env(char *env[])
{
	int i = 0;

	if (env == NULL)
		return (1);
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
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
	return (0);
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

