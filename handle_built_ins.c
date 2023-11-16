#include "shell.h"
/**
 * handle_built_ins - handle built ins commands
 * @lineptr: pointer to buffer that contains input
 * @env: environment
 * @exit_status: exit status of child process
 */
void handle_built_ins(char **lineptr, char **env, int exit_status)
{
	int i, j;

	if (_strcmp(*lineptr, "exit") == 0)
	{
		free(*lineptr);
		exit(exit_status);
	}
	if (_strcmp(*lineptr, "env\n") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			for (j = 0; j <= i; j++)
			{
				if ((_strcmp(env[i], env[j]) == 0) && (i != j))
				{
					break;
				}
			}
			if (j == i)
			{
				write(STDOUT_FILENO, env[i], len(env[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
	}
}
