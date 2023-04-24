#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define DELIM " \n\t\r"

char **tokenize(char *input);
int execute(char **args);

#endif /* HOLBERTON_H */

