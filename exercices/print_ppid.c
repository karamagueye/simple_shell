#include "main.h"
/**
 * main - prints pid of parent process
 * Return: 0 (success)
 */
int main(void)
{
	printf("PID of parent process: %u\n", getppid());
	return (0);
}
