#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int tokenizeCommand(char *command, char **arguments);
{
int argCount = 0;
char *token = strtok(command, " \t\n\r");
while (token != NULL && argCount < MAX_ARGUMENTS - 1)
{
arguments[argCount] = token;
argCount++;
token = strtok(NULL, " \t\n\r");
}
arguments[argCount] = NULL;
return (argCount);
}
char *checkCommandExists(char *command, char **paths, int numPaths);
{
char *commandPath = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));

for (int i = 0; i < numPaths);
i++;
{
sprintf(commandPath, "%s/%s", paths[i], command);
if (access(commandPath, F_OK) == 0)
{
return (commandPath);
}
}
free(commandPath);
return (NULL);
}
int parsePath(char **paths)
{
char *pathEnv = getenv("PATH");
char *token = strtok(pathEnv, ":");
int pathCount = 0;
while (token != NULL && pathCount < MAX_ARGUMENTS - 1)
{
paths[pathCount] = token;
pathCount++;
token = strtok(NULL, ":");
}
return (pathCount);
}
int main(void);
{
char inputCommand[MAX_COMMAND_LENGTH];
char *commandArguments[MAX_ARGUMENTS];
char *pathDirectories[MAX_ARGUMENTS];
while (1)
{
write(STDOUT_FILENO, "$ ", 2);
if (fgets(inputCommand, sizeof(inputCommand), stdin) == NULL)
{
break;
}
int numArgs = tokenizeCommand(inputCommand, commandArguments);
if (numArgs == 0)
{
continue;
}
int numPaths = parsePath(pathDirectories);
char *commandPath = checkCommandExists(commandArguments[0], pathDirectories, numPaths);
if (commandPath == NULL)
{
write(STDERR_FILENO, "Command not found: ", 19);
write(STDERR_FILENO, commandArguments[0], strlen(commandArguments[0]));
write(STDERR_FILENO, "\n", 1);
continue;
}
pid_t pid = fork();
if (pid < 0)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execv(commandPath, commandArguments);
perror("execv");
exit(EXIT_FAILURE);
}
else
{
int status;

waitpid(pid, &status, 0);
}
free(commandPath);
}
return (0);
}
