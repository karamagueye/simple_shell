#include "shell.h"
/**
 * shell - Display a prompt and wait for the user to type a command infinitely
 */
void shell(void)
{
	char *prompt = "$ ";
	char *lineptr = NULL;
	size_t n = 0;
	int gr, l, w;

	while (1)
	{
		w = write(STDOUT_FILENO, prompt, len(prompt));
		if (w == -1)
			perror("write");
		while (1)
		{
			gr = getline(&lineptr, &n, stdin);
			if (gr == -1)
				perror("getline");
			l = len(lineptr);
			if (lineptr[l - 1] == '\n')
				break;
		}
	}
	free(lineptr);
}
