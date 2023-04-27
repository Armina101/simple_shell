#include "shellie.h"

/**
 * check_interactive - checking for interactivity of shell
 * @blue: pointer to the blue_t struct
 * Return: 1 if check is successful,
 * if unsuccessful, 0
 */

int check_interactive(blue_t *blue)
{
	/* Checking for STDIN */
	return (isatty(STDIN_FILENO) && blue->readfd <= 2);
	/* Checking if readfd <= 2 */
}
