#include "shell.h"
/**
 * get_process - forks the current process and execve the child
 * @command: pointer to the first token
 */
void get_process(char *command)
{
	pid_t pid;
	int status;
	extern char **environ;
	char **args;

	args = malloc(sizeof(char *) * 2);
	if (args == NULL)
	{
		perror("malloc");
		exit(5);
	}
	args[0] = command;
	args[1] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(3);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./shell");
			exit(4);
		}
	}
	else
	{
		wait(&status);
		shell();
	}
	free(*args);
}
