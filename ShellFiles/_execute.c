#include "main.h"

void execute_path(char *path, char *arg)
{
	char *args[256], *delim = " ", *token;
	int count = 0, ShellEx = 0, i = 0;
	const char *pathEnv;

	pathEnv = environ;

	token = strtok(arg, delim);
	while (token != NULL)
	{
		args[count++] = token;
		token = strtok(NULL, delim);
	}
	args[count] = NULL;
	
	ShellEx = execve(path, args, pathEnv);

	if (ShellEx == -1)
	{
		free(path);
		/* _print("\n"); */
		perror("Error");
		exit(-1);
	}

	exit(1);

}