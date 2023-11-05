#include "main.h"
/**
 * main - executes the command ls -l /tmp in 5 different child processes
 * Return: 0(success)
 */
int main(void)
{
	pid_t pid;
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status, i;

	i = 0;
	while (i < 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
		}
		if (pid == 0)
		{
			execve(args[0], args, NULL);
		}
		else
		{
			wait(&status);
		}
		i++;
	}
	return (0);
}
