#include "shell.h"

/**
* find_builtin_command - Checks if the command is a builtin
* @vars: Pointer to the struct of shell variables
* Return: Returns a pointer to the function or NULL
*/
void (*find_builtin_command(vars_t *vars))(vars_t *vars)
{
builtins_t builtins[] = {
{"exit", perform_exit},
{"env", print_env},
{"setenv", add_env_variable},
{"unsetenv", remove_env_variable},
{NULL, NULL}
};
builtins_t *builtin;

printf("Checking command: %s\n", vars->av[0]);
for (builtin = builtins; builtin->name != NULL; ++builtin)
{
if (_strcmpr(vars->av[0], builtin->name) == 0)
return (builtin->f);
}
return (NULL);
}

/**
* perform_exit - Exits the shell
* @vars: Pointer to the struct of shell variables
* Return: Nothing
*/
void perform_exit(vars_t *vars)
{
int exit_status;

if (_strcmpr(vars->av[0], "exit") == 0 && vars->av[1] != NULL)
{
exit_status = _atoi(vars->av[1]);
if (exit_status == -1)
{
vars->status = 2;
print_error(vars, ": Invalid number format: ");
_puts2(vars->av[1]);
_puts2("\n");
return;
}
else
}
vars->status = 0;
}
free(vars->buffer);
free(vars->av);
free(vars->commands);
free_env(vars->env);
exit(vars->status);
}

/**
* print_env - Prints the current environment
* @vars: Pointer to the struct of shell variables
* Return: Nothing
*/
void print_env(vars_t *vars)
{
unsigned int i;

for (i = 0; vars->env[i]; i++)
{
_puts(vars->env[i]);
_puts("\n");
}
vars->status = 0;
}

/**
* add_env_variable - Creates an environment variable or edits an existing one
* @vars: Pointer to the struct of shell variables
* Return: Nothing
*/
void add_env_variable(vars_t *vars)
{
char **existing_var;
char *new_value;

if (vars->av[1] == NULL || vars->av[2] == NULL)
{
print_error(vars, ": Invalid number of arguments\n");
vars->status = 2;
return;
}

existing_var = find_env_var(vars->env, vars->av[1]);
if (existing_var == NULL)
create_env_var(vars);
else
{
new_value = create_env_string(vars->av[1], vars->av[2]);
if (new_value == NULL)
{
perror("Error");
free(vars->buffer);
free(vars->commands);
free(vars->av);
free_env(vars->env);
exit(127);
}
free(*existing_var);
*existing_var = new_value;
}
vars->status = 0;
}

/**
* remove_env_variable - Remove an environment variable
* @vars: Pointer to the struct of shell variables
* Return: Nothing
*/
void remove_env_variable(vars_t *vars)
{
char **existing_var, **new_env;
unsigned int i, j;

if (vars->av[1] == NULL)
{
print_error(vars, ": Invalid number of arguments\n");
vars->status = 2;
return;
}

existing_var = find_env_var(vars->env, vars->av[1]);
if (existing_var == NULL)
{
print_error(vars, ": There is no variable to remove");
return;
}

for (i = 0; vars->env[i] != NULL; i++)
;

new_env = malloc(sizeof(char *) * i);
if (new_env == NULL)
{
perror("Error");
vars->status = 127;
perform_exit(vars);
}

for (i = 0; vars->env[i] != *existing_var; i++)
new_env[i] = vars->env[i];

for (j = i + 1; vars->env[j] != NULL; j++, i++)
new_env[i] = vars->env[j];

new_env[i] = NULL;
free(*existing_var);
free(vars->env);
vars->env = new_env;
vars->status = 0;
}
