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
	if ((_strspn(lineptr, " \t\n") == 1024) && (errno == ENOTTY))
	{
		free(lineptr);
		exit(0);
	}
	handle_built_ins(&lineptr, env, exit_status);
	if ((lineptr[0] == '\n') && (lineptr[1] == '\0'))
	{
		free(lineptr);
		shell(name, env, 0);
	}
	if (lineptr[gr - 1] == '\n')
		lineptr[gr - 1] = '\0';
	get_process(&lineptr, name, env);
}
