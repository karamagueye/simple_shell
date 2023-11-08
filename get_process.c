#include "shell.h"
/**
 * get_process - forks the current process and execve the child
 * @command: double pointer to the command
 * @name: name of the program
 */
void get_process(char **command, char *name)
{
	pid_t pid;
	int status;
	char **arguments;

	pid = fork();
	if (pid == -1)
	{
		free(*command);
		perror("fork");
		exit(3);
	}
	arguments = args(*command, " ");
	if (pid == 0)
	{
		if (execve(arguments[0], arguments, environ) == -1)
		{
			free(arguments);
			free(*command);
			perror(name);
			exit(4);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			free(arguments);
			free(*command);
			perror("wait");
			exit(6);
		}
		free(arguments);
		free(*command);
		shell(name);
	}
}
