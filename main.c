#include "shell.h"
/**
 * main - checks code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (success)
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	shell(argv[0], env);
	return (0);
}
