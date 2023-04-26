#include "shellie.h"

/**
 * implement_exit - exits the shell
 * @arg_list: List of arguments from parsing stage
 * @curr_arg: argument input to the shell
 * Return: Always 0
 */

int implement_exit(char **arg_list, char *curr_arg)
{
	int i;

	if (arg_list[1])
	{
		return 0;
	}

	i = _atoi(args[1]);

	if (i >= 256)
	{
		free(curr_arg);
		free(arg_list);
		exit(i - 256);
	}
	else if (i < 0)
	{
		perrorr
	}
}
