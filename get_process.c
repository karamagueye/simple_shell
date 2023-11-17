#include "shell.h"
/**
 * get_process - forks the current process and execve the child
 * @command: double pointer to the command
 * @name: name of the program
 * @env: environment
 */
void get_process(char **command, char *name, char **env)
{
	pid_t pid;
	int status;
	char **arguments;

	arguments = args(*command, " ");
	pid = fork();
	if (pid == -1)
	{
		free(arguments);
		free(*command);
		perror("fork");
		exit(3);
	}
	if (pid == 0)
	{
		exec_command(command, arguments, name);
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
		shell(name, env, WEXITSTATUS(status));
	}
}
