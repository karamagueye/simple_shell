#include "shell.h"
/**
 * _which - search for a file in the path
 * @filename: name of the file
 * Return: full path of the file
 */
char *_which(char *filename)
{
	char **pathname = NULL, *path_copy;
	char *path, *filename_copy, *s;
	int i, pathname_length;
	struct stat st;

	filename_copy = _strdup(filename);
	s = _getenv("PATH");
	pathname = args(s, ":");
	for (i = 0; pathname[i] != NULL; i++)
	{
		path_copy = _strdup(pathname[i]);
		if (path_copy == NULL)
		{
			perror("strdup");
			exit(7);
		}
		pathname_length = len(pathname[i]) + len(filename_copy) + 2;
		path = malloc(sizeof(char) * pathname_length);
		if (path == NULL)
		{
			perror("malloc");
			free(path_copy);
			exit(8);
		}
		strcpy(path, path_copy);
		strcat(path, "/");
		strcat(path, filename_copy);
		if (stat(path, &st) == 0)
		{
			free(pathname);
			free(filename_copy);
			free(path_copy);
			return (path);
		}
		free(path_copy);
		free(path);
	}
	free(filename_copy);
	free(pathname);
	return (NULL);
}
