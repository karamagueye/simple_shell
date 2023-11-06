#include "shell.h"
/**
 * get_args - tokenize command
 * @command: command
 * Return: command tokenized
 */
char **get_args(char *command)
{
	char **args, *token;
	int i;

	args = malloc(sizeof(char *) * 1024);
	if (args == NULL)
	{
		perror("malloc");
		exit(5);
	}
	token = strtok(command, " ");
	for (i = 0; token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
