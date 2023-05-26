#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

extern char **environ;

void shell()
{
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;

    while (1)
	{
        printf("cisfun$ ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL)
		{
            /*Handle end of file condition (Ctrl+D)*/
            printf("\n");
            break;
        }

        if (command[0] == '\n')
		{
            continue;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
		{
            printf("\n");
            break;
        }
        else if (strcmp(command, "env") == 0)
		{
            char **env = environ;
            while (*env != NULL)
			{
                printf("%s\n", *env);
                env++;
            }
            continue;
        }

        pid = fork();

        if (pid == -1)
		{
            /*Fork failed*/
            perror("Fork failed");
            continue;
        }

        if (pid == 0)
		{
            /*Child process*/
            char* arguments[MAX_COMMAND_LENGTH];
            char* token = strtok(command, " ");
            int arg_count = 0;

            while (token != NULL)
			{
                arguments[arg_count] = token;
                arg_count++;
                token = strtok(NULL, " ");
            }

            arguments[arg_count] = NULL;

            if (execvp(arguments[0], arguments) == -1)
			{
                /* Executable not found*/
                fprintf(stderr, "%s: No such file or directory\n", arguments[0]);
                exit(1);
            }
        }
		else
		{
            /*Parent process*/
            int status;
            waitpid(pid, &status, 0);
            printf("Exit status: %d\n", WEXITSTATUS(status));
        }
    }
}

int main()
{
    shell();
    printf("Exiting the shell...\n");
    return 0;
}
