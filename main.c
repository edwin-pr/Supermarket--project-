#include "myshell.h"

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success, or error code
 */
int main(void)
{
	char *input;
	char **args;
	ssize_t read;
	size_t bufsize = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		_puts("cisfun$ ");

		read = getline(&input, &bufsize, stdin);
		if (read == -1)
			break;

		args = parse_input(input);
		if (args[0] != NULL)
		{
			if (is_builtin(args))
				execute_builtin(args);
			else
				execute_command(args);
		}

		free_input(args);
	}

	free(input);
	return (0);
}
