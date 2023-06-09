#include "shell.h"

/**
* _putchar - Writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
* sigint_handler - Handles the SIGINT signal sent to the process
* @sig: The signal number
* Return: Nothing
*/

void sigint_handler(int sig)
{
(void)sig;
_putchar('\n');
write(STDOUT_FILENO, "$ ", 2);
fflush(stdout);
}

/**
* main - Main function for the simple shell program
* @argc: Number of arguments passed to main
* @argv: Array of arguments passed to main
* @environment: Array of environment variables
* Return: 0 or exit status, or unknown
*/
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
size_t len_buffer = 0;
unsigned int is_pipe = 0, i;
vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, 0, NULL, 1};

vars.argv = argv;
vars.env = make_env(environment);
signal(SIGINT, sigint_handler);
if (!isatty(STDIN_FILENO))
is_pipe = 1;
if (is_pipe == 0)
_puts("$ ");
fflush(stdout);

while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
{
vars.count++;
vars.commands = tokenize(vars.buffer, ";");
for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
{
vars.av = tokenize(vars.commands[i], "\n \t\r");
if (vars.av && vars.av[0])
if (find_builtin_command(&vars) == NULL)
check_for_command(&vars);
free(vars.av);
}
free(vars.buffer);
free(vars.commands);
vars.buffer = NULL;
if (is_pipe == 0)
_puts("$ ");
fflush(stdout);
}
if (is_pipe == 0)
_puts("\n");
free_env(vars.env);
free(vars.buffer);
exit(vars.status);
}
