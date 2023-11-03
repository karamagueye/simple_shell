#include "shell.h"
/**
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
}
