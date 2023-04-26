#ifndef SHELLIE_H
#define SHELLIE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define DELIM " \n\t\r"

char **tokenize(char *input);
int execute(char **args);
int betty(void);
int main(void);
int _putchar(char c);
void _puts(char *ptr);

/* Variable for Environment */
extern char **environ;

#endif

