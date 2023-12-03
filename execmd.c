#include "main.h"

/**
 * execmd - execute a command
 * @pathcmd: the command to execute
 * @args: the arguments for the command
 * Return: 0
 */
int execmd(char *pathcmd, char **args)
{
	/* All variable earlier in execute_path are called here intead */
	int ShellEx = 0, *null = NULL;
	char **pathEnv = environ;
	pid_t childId;

	/* start a child process */
	childId = fork();

	if (childId < 0)
	{
		perror("Error");
		free(pathcmd);
		free(args);
		exit(errno);
	}
	else if (childId == 0)
	{
		/* execute the command */
		ShellEx = execve(pathcmd, args, pathEnv);
		/* if the command is not found */
		if (ShellEx == -1)
		{
			free(args);
			free(pathcmd);
			_print("not found!\n");
			exit(errno);
		}
	}
	else
	{
		wait(null);
	}

	return (0);
}
