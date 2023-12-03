#include "main.h"

void builtInFunc(char *arg)
{
    if (strcmp(arg[0], "exit") == 0)
    {
        _print("Exit");
        // break;
        exit(1);
    }
}

void signal_handler(int signum)
{
    (void)signum;
    
    if (signum == SIGINT)
	{
		write(1, "\n", 1);
		write(1, "$ ", 2);
	}
}

char _getEnviron(const char **path)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strcmp(environ[i], "PATH") == 0)
		{
			return (environ[i]);
		}
		i++;
	}

}

char _getENV(const char *path)
{
    size_t pathName;
    int i = 0;

    if (path == NULL)
        return (NULL);

    if (environ == NULL)
        return (NULL);

    pathName = strlen(path);

    while (environ[i] != NULL)
    {
        if (strncmp(environ[i], path, pathName) == 0
            && environ[i][pathName] == '=')
        {
            return &environ[i][pathName + 1];
        }
    }

    return (pathName);

}

int pathExist(const char *path)
{
    const char *evnP = _getEnviron("PATH");
    char tok, *delim = ":", fullPath[256];
    environ = "PATH=";
    fullPath = environ;
    if (evnP == NULL)
        return (0);

    tok = strtok((char *)evnP, delim);
    while (tok != NULL)
    {
        strcat(fullPath, "/");
        strcat(fullPath, path);

        if (access(fullPath, F_OK) == 0)
        {
            return (fullPath);
        }

        tok = strtok(NULL, delim);
        
    }
    
    return (0);
}