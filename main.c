#include "shell.h"
/**
 * main - checks code
 * @argc: argument count
 * @argv: argument vector
 * @env: environment
 * Return: 0 (success)
 */
int main(int argc, char **argv, char **env)
{
	if (argc != 0)
		shell(argv[0], env, 0);
	return (0);
}
