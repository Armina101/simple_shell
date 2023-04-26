#include "shell.h"

/**
* betty - Entry point
* Description: This function calculates the sum of two integers
* and prints the result.
* Return: Always 0 (Success)
*/

int betty(void)
{
int x = 5;
int y = 4;
int sum;

sum = x + y;

printf("The sum of %d and %d is %d\n", x, y, sum);

return (0);
}
