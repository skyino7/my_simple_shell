#include "main.h"

char *pathExist(char *ecmd);
/**
 * builtInFunc - a call to all built in commands for the shell
 * @arg: arguments passed to the shell
 * @argv: argument vector from main function
 * Return: 1 when found and -1 when not a builtin
 */
int builtInFunc(char **arg, char **argv)
{
	(void)argv;
	if (_strcmp(arg[0], "exit") == 0)
		exit(0);
	else if (_strcmp(arg[0], "cd") == 0)
	{
		if (arg[1] == NULL)
		{
			chdir(_getEnviron("HOME"));
			/* write(1, "changed\n", 9); */
		}
		else
			chdir(arg[1]);
		return (1);
	}
	else if (_strcmp(arg[0], "env") == 0)
	{
		int i = 0;
		char **evnp = environ;

		if (evnp == NULL)
		{
			write(STDERR_FILENO, "Path Empty.\n", 13);
			return (-1);
		}


		for (i = 0; evnp[i] != NULL; i++)
		{
			write(STDOUT_FILENO, evnp[i], _strlen(evnp[i]));
			write(STDOUT_FILENO, "\n", 1);
		}

		return (1);

	}
	else
		return (-1);

	return (0);
}

/**
 * signal_handler - signal handler
 * @signum: signal number
 */
void signal_handler(int signum)
{

	if (signum == SIGINT)
	{
		write(1, "\n$ ", 3);
	}
}

/**
 * _getEnviron - get the environment
 * @path: the environment variable "PATH="
 * Return: the environment
 */
char *_getEnviron(char *path)
{
	/* Creating variables for environ and the path environment */
	char **n_environ = environ;
	char *path_env = malloc(strlen(path) + 1); /* memory allocation */

	/* if allocation didn't work it will return (NULL)*/
	if (path_env == NULL)
	{
		free(path_env);/*Just Added It*/
		return (NULL);
	}

	/* loop through the environment variable  till "PATH=" is found */
	while ((path_env = *(n_environ++)) != NULL)
	{
		/**
		 * compare the path with each environment variable using
		 * _strncmp builtin function instead of strcmp
		 */
		/* replaced strcmp with _strncmp builtin function */
		if (_strncmp(path_env, path, _strlen(path)) == 0)
		{
			/* return the directories in the path */
			return (path_env);
		}
	}
	free(path_env);
	return (NULL);
}

/**
 * pathExist - check if the path exists
 * @ecmd: the command to check if it exists
 * Return: the path if command exists in path or NULL
 */
char *pathExist(char *ecmd)
{
	/* get the directories in PATH */
	char *evnP = _getEnviron("PATH="), *evnp_dup = NULL;
	char *tok = NULL, *delim = ":", *fullPath = NULL;

	if (evnP == NULL)
		return (NULL);

	/* Copy envP because strtok modifies the original string */
	evnp_dup = _strdup(evnP);
	if (evnp_dup == NULL)
	{
		free(evnp_dup);
		return (NULL);
	}

	/* tokenize the command */
	tok = strtok(evnp_dup, delim);
	while (tok != NULL)
	{
		if (ecmd[0] != '/')
		{
			fullPath = malloc(_strlen(tok) + _strlen(ecmd) + 3);
			if (fullPath == NULL)
			{
				_print("Memory Allocation Failed");
				/* free(fullPath); Just Added It*/
				return (NULL);
			}

			/* concatenate the path and command */
			_strcpy(fullPath, tok);
			_strcat(fullPath, "/");
			_strcat(fullPath, ecmd);
			_strcat(fullPath, "\0");

			if (access(fullPath, X_OK) == 0)
			{
				/* return the directory with the command */
				/* free(evnp_dup); */
				return (fullPath);
			}
			free(fullPath);
		}
		else
		{
			/* check for absolute path, if the path exists */
			if (access(ecmd, X_OK) == 0)
			{
				/* return the directory with the command */
				/* free(evnp_dup); */
				return (ecmd);
			}
			else
			{
				/* free(evnp_dup); */
				return (NULL);
			}
		}

		tok = strtok(NULL, delim);
		/* free the memory */

	}

	/* free(fullPath); */
	free(evnp_dup);
	return (NULL);
}
