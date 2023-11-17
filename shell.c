#include "shell.h"
/**
 * shell - displays a prompt and waits for input infinitely
 * @name: name of the program
 * @env: environment
 * @exit_status: exit status of child process
 */
void shell(char *name, char **env, int exit_status)
{
	char *prompt = "$ ";
	ssize_t w;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			w = write(STDOUT_FILENO, prompt, len(prompt));
			if (w == -1)
			{
				perror("write");
				exit(1);
			}
		}
		while (1)
			_getline(name, env, exit_status);
	}
}
