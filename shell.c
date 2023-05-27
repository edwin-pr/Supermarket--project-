#include "myshell.h"
/**
 * execute_builtin - Execute a built-in command
 * @args: Array of command arguments
 */
void execute_builtin(char **args)
{
	if (strcmp(args[0], "exit") == 0)
		exit_shell();
	else if (strcmp(args[0], "cd") == 0)
		change_directory(args);
	else if (strcmp(args[0], "env") == 0)
		print_environment();
}
/**
 * execute_command - Execute an external command
 * @args: Array of command arguments
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}
/**
 *  main - Entry point of the shell program
 *  Return: 0 on success, or error code
 */
int main(void)
{
	return (start_shell());
}
