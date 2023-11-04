#include "main.h"
/**
 * main - prints all arguments without using ac
 * Return: 0 (success)
 */
int main(int ac, char **av)
{	
	int i;

	(void)ac;
	for (i = 1; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
