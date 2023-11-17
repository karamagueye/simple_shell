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
 * @name: name of the executable
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
<<<<<<< HEAD
	free(lineptr);
>>>>>>> 966dfa5297fd484a41e9ca0c3af7070cb72121c2
=======
>>>>>>> 466aa37aaa751975329fa44dfd4454f601ecc8e0
}
