#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

char *_getenv(const char *path, char **env)
{

    size_t pathLen;
    int i = 0;

    if (path == NULL || env == NULL)
        return NULL;

    pathLen = strlen(path);

    for (i = 0; env[i] != NULL; i++)
    {
        if (strncmp(env[i], path, pathLen) == 0 && env[i][pathLen] == '=')
            return &env[i][pathLen + 1];
    }

    return NULL;
}

int main(int argc, char *argv[], char *env[])
{

    char *pathName = "PATH", *buffer = "Command";
    char *pathValue, *copyPath, **pathToken, *pathDelim = ":", *cmdPath;
    int i = 0;

    pathValue = _getenv(pathName, env);

    copyPath = strdup(pathValue);

    pathToken = strtok(copyPath, pathDelim);

    cmdPath = malloc(strlen(buffer) + strlen(pathToken) + 2);

    while (pathToken[i] !=  NULL)
    {
        strcpy(cmdPath, pathToken[i]);
        strcat(cmdPath, "/");
        strcat(cmdPath, buffer);
        strcat(cmdPath, "\0");
        printf("%s", pathToken[i]);
        i++;
    }
    pathToken = strtok(NULL, pathDelim);

    free(copyPath);
    free(cmdPath);

    /* if (pathName != NULL)
        printf("Found: %s: %s\n", pathName, pathValue);
    else
        printf("%s not found\n", pathName); */

    // getline(buffer, bufferSize, stdin)

    //Tokenize Buffer

    return 0;
}
