#include "shell.h"
/**
 * shell - Display a prompt and wait for the user to type a command infinitely
 * @name: name of the executable
 */
void shell(char *name, char **env, int exit_status)
{
	char *prompt = "$ ", *lineptr = NULL;
	size_t n = 0;
	ssize_t gr, w;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			w = write(STDOUT_FILENO, prompt, len(prompt));
		if (w == -1)
		{
			perror("write");
			exit(1);
		}
		while (1)
		{
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
				else
				{
					free(lineptr);
					perror("getline");
					exit(2);
				}
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
				break;
			else if (lineptr[gr - 1] == '\n')
				lineptr[gr - 1] = '\0';
			get_process(&lineptr, name, env);
		}
	}
}
