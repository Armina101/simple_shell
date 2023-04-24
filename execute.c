#include "holberton.h"

/**
* execute - Execute a given command
* @args: The arguments to the command
*
* Return: 0 on success, 1 on failure
*/
int execute(char **args)
{
pid_t pid;
int status;

if (args == NULL || args[0] == NULL)
return (1);

pid = fork();
if (pid == -1)
return (1);

if (pid == 0)
{
if (execve(args[0], args, NULL) == -1)
{
fprintf(stderr, "%s: command not found\n", args[0]);
exit(EXIT_FAILURE);
}
}
else
{
do {
if (waitpid(pid, &status, WUNTRACED) == -1)
{
perror("waitpid");
exit(EXIT_FAILURE);
}
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

return (0);
}

