#include "myshell.h"
/**
 * prompt - display prompt
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", strlen("$ "));
}
/**
 * sigint_handler - handles the signals to shell
 * @signal: input signal
 * Return: prompt on success
 */

void sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		prompt();
		fflush(stdout);
	}
}
