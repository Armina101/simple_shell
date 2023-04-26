#include "shellie.h"

/**
* main - Entry point for the simple shell
* Return: 0 on success, 1 on failure
*/
int main(void)
{
char *input = NULL, **args = NULL;
size_t input_size = 0;
ssize_t bytes_read = 0;
int status = 0;

do {
printf("#cisfun$ ");
bytes_read = getline(&input, &input_size, stdin);
if (bytes_read == -1)
{
if (errno == EINTR) /* Interrupted system call */
{
clearerr(stdin); /* Clear the error and try again */
continue;
}
else
{
perror("getline");
status = 1;
break;
}
}
args = tokenize(input);
if (args == NULL)
{
fprintf(stderr, "Failed to tokenize input\n");
status = 1;
break;
}
status = execute(args);
free(args);
} while (status == 0);

free(input);
free(args); /* Free args here to address reachable memory issue */
return (status);
}

