#include "shell.h"
/**
 * shell - Display a prompt and wait for the user to type a command infinitely
 */
void shell(void)
{
	char *prompt = "$ ", *lineptr = NULL;
	size_t n = 0;
	ssize_t gr, w;

	while (1)
	{
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
				free(lineptr);
				perror("getline");
				exit(2);
			}
			if (lineptr[gr - 1] == '\n')
				lineptr[gr - 1] = '\0';
			get_process(lineptr);
		}
	}
	free(lineptr);
}
