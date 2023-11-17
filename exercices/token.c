#include "shell.h"
/**
 * 
 */
int list_words(char *command, char *delim)
{
	char *token;
	int wordlist = 0;

	token = strtok(command, delim);
	while (token != NULL)
	{
		wordlist++;
		token = strtok(NULL, delim);
	}
	return (wordlist);
}
/**
 *
 */
char **args(char *command, char *delim)
{
	int num_words, i = 0;
	char **args = NULL;
	char *token, *command_copy;

	command_copy = strdup(command);
	num_words = list_words(command_copy, delim);
	free(command_copy);
	args = malloc(sizeof(char *) * (num_words + 1));
	if (args == NULL)
	{
		perror("malloc");
		exit(6);
	}
	token = strtok(command, delim);
	for (i = 0; token != NULL; i++)
	{
		if (token[0] != '\0')
			args[i] = token;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	return (args);
}
