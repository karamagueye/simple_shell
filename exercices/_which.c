#include "main.h"
/**
 *
 */
int _which(char *filename)
{
	char **pathname = NULL, *path_copy;
	char *path;
	int i, pathname_length;
	char *s;
	struct stat st;

	s = getenv("PATH");
	pathname = args(s, ":");
	for (i = 0; pathname[i] != NULL; i++)
	{
		path_copy = strdup(pathname[i]);
		if (path_copy == NULL)
		{
			perror("strdup");
			exit(7);
		}
		pathname_length = len(pathname[i]) + len(filename) + 2;
		path = malloc(sizeof(char) * pathname_length);
		if (path == NULL)
		{
			perror("malloc");
			free(path_copy);
			exit(8);
		}
		strcpy(path, path_copy);
		strcat(path, "/");
		strcat(path, filename);
		if (stat(path, &st) == 0)
		{
			printf("found\n");
			free(path_copy);
			free(path);
			return (0);
		}
		free(path_copy);
		free(path);
	}
	free(pathname);
	printf("not found\n");
	return (1);
}
/**
 *
 */
int main(int ac, char **av)
{
	if (ac > 1)
		_which(av[1]);
	else
		printf("usage: %s filename\n", av[0]);
	return (0);
}
