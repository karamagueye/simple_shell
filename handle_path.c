#include "shell.h"
/**
 *
 */
char **handle_path(char **command, char *name)
{
	char **arguments, *token, *path;

	arguments = args(*command, " ");
	token = strtok(arguments[0], "/");
	while (token != NULL)
	{
		token = strtok(NULL, "/");
	}
	path = _which(token);
	if (path == NULL)
	{
		perror(name);
		free(*command);
		exit(8);
	}
	arguments[0] = path;
	free(path);
	return (arguments);
}
