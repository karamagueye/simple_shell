#include "shell.h"
/**
 * _getenv - gets an environment variable
 * @name: name of the variable
 * Return: the variable if found, NULL otherwise
 */
char *_getenv(const char *name)
{
	int i;
	char *var_name, *environment;

	for (i = 0; environ[i] != NULL; i++)
	{
		environment = _strdup(environ[i]);
		var_name = strtok(environment, "=");
		if (_strcmp(var_name, (char *)name) == 0)
		{
			free(environment);
			return (environ[i]);
		}
		free(environment);
	}
	return (NULL);
}
