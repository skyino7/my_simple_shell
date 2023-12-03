#include "main.h"

int main()
{
    char *cmd;
    size_t cmdsize;
    ssize_t readlines;
	pid_t childId;
	/* int shellEx; */
	char *path;
	int checkTem = 0;

    cmd = NULL;
    cmdsize = 0;
    readlines = 0;

	checkTem = isatty(0);

	signal(SIGINT, signal_handler);

    while (1)
    {
		if (checkTem == 1)
			write(1, "$ ", 2);
		
        readlines = getline(&cmd, &cmdsize, stdin);

		if (cmd[strlen(cmd) - 1] == '\n') {
			cmd[strlen(cmd) - 1] = '\0';
		}

			path = cmd;

			if (readlines == -1)
			{
				free(cmd);
				exit(0);
			}

			childId = fork();

			if (childId < 0)
			{
				perror("Error");
				free(cmd);
				exit(0);
			}
			else if (childId == 0)
			{
				/* ShellEx = execve(cmd, &cmd, envp);  /bin/ls */
				execute_path(path, cmd);
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
				/* free(cmd); */
			}
		
    }

	free(cmd);

	return (0);
}