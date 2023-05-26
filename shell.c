#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 100

void prompt() {
    char promptSymbol[] = "#cisfun$ ";
    write(STDOUT_FILENO, promptSymbol, sizeof(promptSymbol) - 1);
}

void execute_command(char* command) {
    pid_t pid = fork();

    if (pid == -1) {
        strerror("fork");
        _exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        char* args[] = {command, NULL};
        execve(command, args, NULL);
        char errorMsg[] = "./shell: No such file or directory\n";
        write(STDERR_FILENO, errorMsg, sizeof(errorMsg) - 1);
        _exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            // Child process exited successfully
            return;
        } else {
            char errorMsg[] = "./shell: No such file or directory\n";
            write(STDERR_FILENO, errorMsg, sizeof(errorMsg) - 1);
        }
    }
}

void shell() {
    while (1) {
        prompt();

        char command[MAX_COMMAND_LENGTH];
        ssize_t bytes_read = read(STDIN_FILENO, command, sizeof(command));

        if (bytes_read == -1) {
            perror("read");
            _exit(EXIT_FAILURE);
        } else if (bytes_read == 0) {
            // End of file (Ctrl+D) or error
            char exitMsg[] = "\nExiting shell...\n";
            write(STDOUT_FILENO, exitMsg, sizeof(exitMsg) - 1);
            break;
        }

        // Remove newline character
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            char errorMsg[] = "./shell: No such file or directory\n";
            write(STDERR_FILENO, errorMsg, sizeof(errorMsg) - 1);
            break;
        }

        execute_command(command);
    }
}

int main() {
    char welcomeMsg[] = "Welcome to the Simple Shell!\n";
    write(STDOUT_FILENO, welcomeMsg, sizeof(welcomeMsg) - 1);

    shell();

    return 0;
}
