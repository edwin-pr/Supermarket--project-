#include "myshell.h"
/**
 * prompt - print prompt symbol
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "cisfun$ ", strlen("cisfun$ "));
}
