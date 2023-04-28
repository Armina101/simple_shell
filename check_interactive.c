#include "shell.h"

/**
 * check_interactive - checking for interactivity of shell
 * @vars: pointer to the vars_t struct
 * Return: 1 if check is successful,
 * if unsuccessful, 0
 */

int check_interactive(vars_t *vars)
{
	/* Checking for STDIN */
	return (isatty(STDIN_FILENO) && vars->readfd <= 2);
	/* Checking if readfd <= 2 */
}

/**
 * command_exit - execute and exit
 * @c: command
 * Return: void
 */
void command_exit(char *c)
{
	int status = system(c);

	if (status == -1)
	{
		perror("Error");
		exit(1);
	}
	else if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	{
		exit(WEXITSTATUS(status));
	}
}

