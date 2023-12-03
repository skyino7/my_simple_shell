#include "main.h"

int execute_path(char *ecmd, char **argv);
/**
 * execute_path - execute a command
 * @ecmd: the command to execute
 * @argv: argument vector from main function
 * Return: 0
 */
int execute_path(char *ecmd, char **argv)
{
	char *pathcmd, **args = NULL;
	int count = 1;

	/* tokenize the arguments and assign to args*/
	args = tokenize(ecmd);

	if (args == NULL)
	{
		free(args);
		free(ecmd); /*Just Added*/
		return (0);
	}

	/* NOTE: Calling pathExist funciton */
	/* check if the path exists and assign path with the argument to pathcmd */
	pathcmd = pathExist(args[0]);

	/* call builtInFunc or execmd */
	if (pathcmd == NULL && builtInFunc(args, argv) == 1)
	{
		return (0); /* Calling buitin functions of path is NULL*/
	}
	else if (pathcmd != NULL)
	{
		/**
		 * implemented a new function instead of calling execve directly
		 * also, moved the call of child process to execmd
		 */
		execmd(pathcmd, args);
		/* Having an issue, when i free here*/

		/* free(args);
		free(pathcmd); */
	}
	else
	{
		/**
		 * NOTE: his can also be removed if you prefer but this is just to
		 *cover up the called commands if not found
		 */
		wait(NULL);
		/* free(args); */
		/* free(pathcmd); */
		_printnotfound(&count, args, argv);

		/* _print("Command not found\n"); */
	}

	free(args); /* Just Added It */
	free(pathcmd);

	return (0);
}
