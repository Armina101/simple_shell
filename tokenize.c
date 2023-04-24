#include "holberton.h"

/**
* tokenize - Tokenize a given string
* @input: The string to tokenize
*
* Return: An array of tokens
*/
char **tokenize(char *input)
{
char *token;
int i = 0;
char **tokens = malloc(sizeof(char *) * BUFFER_SIZE);
if (!tokens)
return (NULL);

token = strtok(input, DELIM);
while (token)
{
tokens[i] = token;
i++;
if (i >= BUFFER_SIZE)
break;
token = strtok(NULL, DELIM);
}
tokens[i] = NULL;
return (tokens);
}

