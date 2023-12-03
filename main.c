#include "main.h"

/**
 * main - entry point
 * @c: argument count
 * @argv: argument from main
 * Return: 0
 */
int main(int c, char **argv) /* added argument vectors and count */
{
	char *cmd;
	size_t cmdsize;
	ssize_t readlines;
	int checkTem = 0;
	(void)c;
	/* Removed ecmd from here and used only cmd, making code consize */

	cmd = NULL;
	cmdsize = 0;
	readlines = 0;

	checkTem = isatty(0);

	signal(SIGINT, signal_handler);

	while (1)
	{
		if (checkTem)
			_print("$ "); /* used the _print function to make cod e consize */
		readlines = getline(&cmd, &cmdsize, stdin);
		/* moved this condition block here to make it relative to getline*/
		if (readlines == -1)
		{
			free(cmd);
			exit(0);
		}

		if (cmd[_strlen(cmd) - 1] == '\n')
			cmd[_strlen(cmd) - 1] = '\0';

		/* if (_strcmp(cmd, "") == 0)
			continue; */

		if (cmd == NULL)
		{
			perror("Error");
			/* free(cmd); */
			return (1);
		}

		/* Calling execute_path function */
		execute_path(cmd, argv);
	}

	return (errno);
}
