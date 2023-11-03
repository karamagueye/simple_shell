#include "shell.h"
/**
 * get_process - forks the current process and execve the child
 */
void get_process(void)
{
	pid_t pid;
	int status;
	extern char **environ;
	char *args[] = {"/bin/ls", NULL};	

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
			perror("execve");
			exit(4);
		}
	}
	else
	{
		wait(&status);
		shell();
	}
}
