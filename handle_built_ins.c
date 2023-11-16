#include "shell.h"
/**
 *
 */
void handle_built_ins(char **lineptr, char **env, int exit_status)
{
	int i;

	if (_strcmp(*lineptr, "exit\n") == 0)
	{
		free(*lineptr);
		exit(exit_status);
	}
	if (_strcmp(*lineptr, "env\n") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			write(STDOUT_FILENO, env[i], len(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}
