#ifndef MAIN_H
#define MAIN_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

void prompt(void);
void sigint_handler(int signal);
void execute_builtin(char **args);
void execute_command(char **args);

#endif
