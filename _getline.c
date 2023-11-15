#include "shell.h"
/**
 * _getline - gets input from stdin or piped input
 * @name: name of the program
 * @env: environment
 * @exit_status: exit status of child process
 */
void _getline(char *name, char **env, int exit_status)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t gr;
	int i;

	gr = getline(&lineptr, &n, stdin);
	if (gr == -1)
	{
		if ((errno == 0) || (errno == ENOTTY))
		{
			if (errno == 0)
				write(STDOUT_FILENO, "\n", 1);
			free(lineptr);
			exit(0);
		}
		free(lineptr);
		perror("getline");
		exit(2);
	}
	if (_strcmp(lineptr, "exit\n") == 0)
	{
		free(lineptr);
		exit(exit_status);
	}
	if (_strcmp(lineptr, "env\n") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
		{
			write(STDOUT_FILENO, env[i], len(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	if ((lineptr[0] == '\n') && (lineptr[1] == '\0'))
	{
		free(lineptr);
		shell(name, env, 0);
	}
	if (lineptr[gr - 1] == '\n')
		lineptr[gr - 1] = '\0';
	get_process(&lineptr, name, env);
}
