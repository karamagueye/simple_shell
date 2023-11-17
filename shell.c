#include "shell.h"
/**
<<<<<<< HEAD
 * Description: Display a prompt and wait for the user to type a command.
 * A command line always ends with a new line.
 * Return: nathing
 */

int main()
{
        char input[100];
        char prompt[] = "simple_shell";

        while (1)
        {
        printf("simple_shell> ");
        char command[100];
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
                printf("\n");
                break;
        }
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n')
        {
                command[len - 1] = '\0';
        }
        if (system(command) == -1)
        {

                printf("Erreur : commande not found\n");
        }

        return 0;
        }
=======
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
				perror("getline");
				exit(2);
			}
			if (lineptr[gr - 1] == '\n')
				lineptr[gr - 1] = '\0';
			get_process(lineptr);
		}
	}
	free(lineptr);
>>>>>>> 966dfa5297fd484a41e9ca0c3af7070cb72121c2
}
