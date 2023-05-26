#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void shell() {
    char command[MAX_COMMAND_LENGTH];
	pid_t pid;
    while (1) {
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL) {
            /* Handle end of file condition (Ctrl+D)*/
            printf("\n");
            break;
        }

        if (command[0] == '\n') {
            continue;
        }

        command[strcspn(command, "\n")] = '\0';

        pid = fork();

        if (pid == -1) {
            /* Fork failed*/
            perror("Fork failed");
            continue;
        }

        if (pid == 0) {
            /* Child process*/
            if (execlp(command, command, NULL) == -1) {
                /* Executable not found*/
                fprintf(stderr, "%s: No such file or directory\n", command);
                exit(1);
            }
        } else {
            /* Parent process*/
            wait(NULL);
            printf("\n");
        }
    }
}

int main() {
    shell();
    return 0;
}

