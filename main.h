#ifndef MAIN_H
#define MAIN_H

/* Macro for the number of ARGS */
#define MAX_ARGS 256

/* System Libraries called */
#include <stddef.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

extern char **environ;

/* Custom implemented string functions */
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);

int _putchar(char c);
int _print(char *str);
int _printnotfound(int *count, char **arg, char **argv);

/* functions called */
int execute_path(char *ecmd, char **argv);
int builtInFunc(char **arg, char **argv);
void signal_handler(int signum);
char *pathExist(char *ecmd);
char **tokenize(char *ecmd);
int execmd(char *pathcmd, char **args);

char *_getEnviron(char *path);

#endif /* MAIN_H */
