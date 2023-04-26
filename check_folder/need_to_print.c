#include "shellie.h"

/**
 * _putchar - writes to stdout
 * @c: char to be printed
 * Return: 1
 * if unsuccessful, returns -1 and sets errno accordingly
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - works just exactly like puts
 * @ptr: pointer
 * Return: nothing
 */

void _puts(char *ptr)
{
	int i;

	i = 0;

	while (ptr[i] != NULL)
	{
		_putchar(ptr[i]);
		i++;
	}
}
