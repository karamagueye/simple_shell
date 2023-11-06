#include "shell.h"
/**
 * get_process - forks the current process and execve the child
 * @command: pointer to the command
 * @name: name of the program
 */
void get_process(char *command, char *name)
{
	pid_t pid;
	int status;
	char **args = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(3);
	}
	args = get_args(command);
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			free_2d_array(args);
			perror(name);
			exit(4);
		}
		free_2d_array(args);
	}
	else
	{
		if (wait(&status) == -1)
		{
			free_2d_array(args);
			perror("wait");
			exit(6);
		}
		shell(name);
	}
}
