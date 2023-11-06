#include "shell.h"
/**
 * get_process - forks the current process and execve the child
 * @command: pointer to the command
 * @name: name of the program
 */
void get_process(char *command, char *name)
{
	pid_t pid;
	char **args, *token;
	int status, i;

	args = malloc(sizeof(char *) * 1024);
	if (args == NULL)
	{
		perror("malloc");
		exit(5);
	}
	token = strtok(command, " ");
	for (i = 0; token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	pid = fork();
	if (pid == -1)
	{
		free_2d_array(args);
		perror("fork");
		exit(3);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(name);
			exit(4);
		}
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
