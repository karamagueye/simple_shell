#include "shell.h"
/**
 * exec_command - executes a command
 * @command: command to execute
 * @arguments: command arguments
 * @name: name of the program
 */
void exec_command(char **command, char **arguments, char *name)
{
	if (_strchr(*command, '/') != NULL)
	{
		if (execve(arguments[0], arguments, environ) == -1)
		{
			free(arguments);
			free(*command);
			if (errno == ENOENT)
				perror("not found");
			else
				perror(name);
			exit(4);
		}
	}
	else
	{
		if (_execvp(arguments[0], arguments) == -1)
		{
			free(arguments);
			free(*command);
			if (errno == ENOENT)
				perror("not found");
			else
				perror(name);
			exit(12);
		}
	}
}
/**
 * _execvp - search for a command in the path and executes it
 * @filename: name of the command
 * @arguments: arguments of the command
 * Return: 0 if success, -1 otherwise
 */
int _execvp(char *filename, char **arguments)
{
	char *path;

	path = _which(filename);
	if (path == NULL)
	{
		return (-1);
	}
	if (execve(path, arguments, environ) == -1)
	{
		free(path);
		perror("execve");
		return (-1);
	}
	return (0);
}
