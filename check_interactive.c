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
