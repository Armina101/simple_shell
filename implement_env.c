#include "shellie.h"

/**
 * implement_env - prints the current environment
 * Return: nothing
 */

void implement_env(void)
{
	int a;

	a = 0;
	while (environ[a] != 0)
	{
		_puts(environ[a]);
		_puts("\n");
		a++;
	}
	return (1);
}
