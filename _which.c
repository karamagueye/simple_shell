#include "shell.h"
/**
 * _which - search for a file in the path
 * @filename: name of the file
 * Return: full path of the file
 */
char *_which(char *filename)
{
	char **pathname = NULL, *path_copy, *path, *filename_copy, *s;
	int i;
	struct stat st;

	filename_copy = _strdup(filename);
	if (filename_copy == NULL)
		return (NULL);
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
		path = malloc(sizeof(char) * (len(pathname[i]) + len(filename_copy) + 2));
		if (path == NULL)
		{
			perror("malloc");
			free(path_copy);
			exit(8);
		}
		_strcpy(path, path_copy);
		_strcat(path, "/");
		_strcat(path, filename_copy);
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
