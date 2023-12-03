#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

void signal_handler(int signum);
int _putchar(char c);
int _print(char *str);
void execute_path(char *path, char *arg);
void builtInFunc(char **arg);
char _getEnviron(const char **path);
char _getENV(const char *path);
int pathExist(const char *path);

#endif /* MAIN_H */
